import pandas as pd
import matplotlib
matplotlib.use('TkAgg') # 창 띄우기 모드
import matplotlib.pyplot as plt
import tkinter as tk
from tkinter import scrolledtext, messagebox
import matplotlib.font_manager as fm

# [한글 폰트 설정] WSL에 설치한 'NanumGothic' 적용
plt.rc('font', family='NanumGothic')
plt.rcParams['axes.unicode_minus'] = False # 마이너스 기호 깨짐 방지

def run_analysis():
    # 1. 데이터 로딩
    try:
        df = pd.read_csv('scanner_log.csv')
    except FileNotFoundError:
        messagebox.showerror("에러", "scanner_log.csv 파일이 없습니다.\nmake를 먼저 실행해주세요.")
        return

    # 2. 데이터 분석
    total_time = df['Time_ns'].max()
    laser_on_count = df[df['Laser_On'] == 1].shape[0]
    error_count = df[df['Error_Sensor'] == 1].shape[0]
    
    # 결과 텍스트 생성 (회사명 제거됨)
    report_text = f"""
========================================
   [ Lithography Scanner Log Report ]
========================================

1. 총 가동 시간   : {total_time} ns
2. 레이저 노광 횟수: {laser_on_count} Shots
3. 인터락(에러) 감지: {error_count} 회

----------------------------------------
[진단 결과]
"""
    if error_count > 0:
        report_text += "🚨 경고: 공정 중 인터락이 발생했습니다!\n   -> 장비 점검(Focus/Leveling)이 필요합니다."
    else:
        report_text += "✅ 정상: 모든 공정이 안전하게 완료되었습니다."
    
    # 3. GUI 창에 텍스트 출력
    text_area.delete(1.0, tk.END) 
    text_area.insert(tk.INSERT, report_text)
    
    # 4. 그래프 데이터 전역변수 설정
    global current_df
    current_df = df

def show_graph():
    if 'current_df' not in globals():
        return

    df = current_df
    plt.figure(figsize=(12, 6))
    
    # 상태 변화
    plt.plot(df['Time_ns'], df['State'], label='Scanner State', color='blue')
    
    # 노광 구간
    plt.fill_between(df['Time_ns'], 0, 16, where=(df['Laser_On']==1), color='lime', alpha=0.3, label='Exposure (Laser)')
    
    # 에러 지점
    error_points = df[df['Error_Sensor'] == 1]['Time_ns']
    if len(error_points) > 0:
        plt.scatter(error_points, [15]*len(error_points), color='red', marker='X', s=100, label='Interlock Event', zorder=5)

    # [제목 수정] 회사명 제거
    plt.title(f'Lithography Scanner Process Analysis', fontsize=15)
    plt.xlabel('Time (ns)')
    plt.ylabel('State Code')
    plt.yticks(range(16))
    plt.grid(True, alpha=0.5)
    plt.legend()
    plt.show()

# --- GUI 메인 윈도우 ---
root = tk.Tk()
root.title("Scanner Log Analyzer") # 제목 변경
root.geometry("1200x800")

label = tk.Label(root, text="스캐너 로그 분석기", font=("NanumGothic", 16, "bold")) # 폰트 적용
label.pack(pady=10)

btn_analyze = tk.Button(root, text="1. 로그 분석 및 리포트 보기", command=run_analysis, width=30, height=2, bg="lightblue")
btn_analyze.pack(pady=5)

btn_graph = tk.Button(root, text="2. 상세 그래프 확인 (Waveform)", command=show_graph, width=30, height=2, bg="lightgreen")
btn_graph.pack(pady=5)

text_area = scrolledtext.ScrolledText(root, width=100, height=40, font=("NanumGothic", 10)) # 폰트 적용
text_area.pack(pady=10)



root.mainloop()