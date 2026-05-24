#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float calculate_angle(int h, int m)
{
    // 将小时转换为12小时制
    h = h % 12;
    
    // 计算时针角度：每小时30度 + 每分钟额外0.5度
    float hour_angle = h * 30 + m * 0.5;
    
    // 计算分针角度：每分钟6度
    float minute_angle = m * 6;
    
    // 计算夹角的绝对值
    float angle = abs(hour_angle - minute_angle);
    
    // 返回较小的夹角（如果大于180度，则取补角）
    return min(angle, 360 - angle);
}

int main()
{
    int h, m;
    char colon;
    cin >> h >> colon >> m;
    cout << fixed << setprecision(3) << calculate_angle(h, m);
    return 0;
}
