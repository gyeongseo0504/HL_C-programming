#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from datetime import datetime
import threading
import time

class LatencyTester:
    def __init__(self):
        rospy.init_node('latency_tester')
        
        # Publisher 생성
        self.pub = rospy.Publisher('/latency_topic', String, queue_size=10)
        
        # Subscriber 생성  
        rospy.Subscriber('/latency_topic', String, self.callback)
        
        # 로그 파일 생성
        self.log_file = open('latency_log.txt', 'w')
        self.log_file.write('=== ROS1 Latency Test (10ms interval, 10 minutes) ===\n')
        self.log_file.write('Test Start: {}\n\n'.format(datetime.now().strftime("%Y-%m-%d %H:%M:%S")))
        self.log_file.flush()
        
        self.count = 0
        
    def callback(self, msg):
        receive_time = datetime.now()
        
        # 메시지에서 보낸 시간 추출
        parts = msg.data.split('|')
        if len(parts) >= 2:
            send_time_str = parts[1]
            
            # 지연시간 계산 (밀리초 단위)
            try:
                send_time = datetime.strptime(send_time_str, "%Y-%m-%d %H:%M:%S.%f")
                latency_ms = (receive_time - send_time).total_seconds() * 1000
                
                # 로그: 받은 메시지, 시간, 지연시간
                log_line = '[RECV] {} - {} | 지연: {:.2f}ms\n'.format(
                    receive_time.strftime("%H:%M:%S.%f")[:-3], msg.data, latency_ms)
                print(log_line.strip())
                self.log_file.write(log_line)
                self.log_file.flush()
            except ValueError:
                pass
    
    def publish_messages(self):
        rate = rospy.Rate(100)  # 100Hz = 10ms 주기
        
        while not rospy.is_shutdown():
            # 현재 시간과 카운트 포함한 메시지 생성
            send_time = datetime.now()
            msg = String()
            msg.data = 'Message {}|{}'.format(self.count, send_time.strftime("%Y-%m-%d %H:%M:%S.%f")[:-3])
            
            self.pub.publish(msg)
            
            # 로그: 보낸 메시지와 시간
            log_line = '[SEND] {} - {}\n'.format(send_time.strftime("%H:%M:%S.%f")[:-3], msg.data)
            print(log_line.strip())
            self.log_file.write(log_line)
            self.log_file.flush()
            
            self.count += 1
            rate.sleep()
    
    def run_test(self):
        print("=== ROS1 Latency Test Started ===")
        print("10ms 주기로 메시지 발행, 지연시간 측정 중...")
        print("latency_log.txt 파일에 기록됩니다\n")
        
        # Publisher 스레드 시작
        pub_thread = threading.Thread(target=self.publish_messages)
        pub_thread.daemon = True
        pub_thread.start()
        
        # 10분(600초) 동안 실행
        start_time = time.time()
        duration = 600  # 10분 = 600초
        
        while (time.time() - start_time) < duration and not rospy.is_shutdown():
            rospy.sleep(0.1)
        
        # 정리
        print("\n=== Test Completed ===")
        print("총 메시지: {}개".format(self.count))
        print("latency_log.txt 파일 확인")
        
        self.log_file.write('\n=== Test End: {} ===\n'.format(datetime.now().strftime("%Y-%m-%d %H:%M:%S")))
        self.log_file.close()

if __name__ == '__main__':
    try:
        tester = LatencyTester()
        tester.run_test()
    except rospy.ROSInterruptException:
        pass
