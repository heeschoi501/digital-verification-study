import tkinter as tk
from tkinter import scrolledtext
import pandas as pd
import matplotlib
matplotlib.use('TkAgg')

def load_and_show():
    log_area.delete(1.0, tk.END)
    
    try:
        # CSV 파일 읽기
        df = pd.read_csv('modular_log.csv')
        
        if df.empty:
            log_area.insert(tk.END, "⚠️ CSV file is empty.\n")
            return

        log_area.insert(tk.END, "=== 🛠️ Modular Scanner System Log ===\n\n")
        
        for index, row in df.iterrows():
            time = row['Time_ns']
            name = row['Phase_Name']
            laser = "🔴 OFF" if row['Laser_Active'] == 0 else "🟢 ON"
            
            # [수정 완료] Log_Msg -> Event_Msg (생성기 코드와 이름 통일)
            msg = row['Event_Msg'] 
            
            line = f"[{time:>5} ns] {name:<12} | Laser:{laser} | {msg}\n"
            log_area.insert(tk.END, line)
            
            if row['Laser_Active'] == 1:
                line_idx = int(log_area.index('end-1c').split('.')[0])
                log_area.tag_add("laser", f"{line_idx}.0", f"{line_idx}.end")
                log_area.tag_config("laser", background="#ccffcc")

        log_area.insert(tk.END, "\n✅ Analysis Complete.")
        
    except Exception as e:
        log_area.insert(tk.END, f"❌ Error: {str(e)}\n")

# GUI Setup
root = tk.Tk()
root.title("Scanner System Monitor")
root.geometry("800x500")

lbl = tk.Label(root, text="Lithography Scanner System Viewer", font=("Arial", 14, "bold"))
lbl.pack(pady=10)

frame = tk.Frame(root)
frame.pack(padx=10, pady=10, fill='both', expand=True)

log_area = scrolledtext.ScrolledText(frame, width=90, height=20, font=("Consolas", 10))
log_area.pack(side='left', fill='both', expand=True)

btn = tk.Button(root, text="🔄 Refresh Log", command=load_and_show, bg="lightblue", height=2)
btn.pack(fill='x', padx=10, pady=5)

root.after(1000, load_and_show) 
root.mainloop()