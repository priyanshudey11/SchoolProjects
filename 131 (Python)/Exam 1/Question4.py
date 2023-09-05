start_time= 812
end_time=1185
timespent= end_time- start_time
money=timespent*0.05
hours=timespent//60
minutes=timespent%60
print("Your lasted ",hours,'h',minutes,"m"," and cost $",round(money,2),'.',sep="")