/*****************
 @Author Hikky
 @Date 2018/2/26
 @DevelopmentEnvironment Xcode9.2
 Detect "Mood Point" to the console
 According to "Rikei Ga Koi Ni Ochita Node Shoumei Shite Mita" written by Yamamoto Arihred(@man_Arihred)
 ******************/

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    double MoodPoint = 0,p[5],x[5];
    int Member,GathAtt; //Memberは計測場所の評価者,GathAttは当事者への注目者の数に用いる
    puts("Wellcome to the Mood Detection.");
    puts("How to use?");
    puts("It's in the following Four Survey before.");
    puts("1.People's rating"); //美しさ指数
    puts("2.People's attention"); //第三者指数
    puts("3.Illuminance of the place"); //照度指数
    puts("4.Noise of the place"); //静けさ指数
    puts("5.Look up each other silence times"); //見つめ合い指数
    puts("OK? Let's Start!");
    printf("Evaluator Member is "); //評価者人数
    scanf("%d", &Member);
    int MemberPoint[Member];
    x[0] = 0.0;
    for (int i = 0; i < Member; i++) {
        printf("Member's Number %d Point is ", i + 1); //n人目の評価(-inf<=x<=100)
        scanf("%d", &MemberPoint[i]);
        x[0] += (1.0 / 5.0) * (double)MemberPoint[i];
    }
    p[0] = (x[0] /= Member);
    printf("We're gathering attention by "); //第三者指数
    scanf("%d", &GathAtt);
    if (GathAtt != 0)
        p[1] = GathAtt * -10000.0;
    else
        p[1] = 20;
    printf("Illuminance(lux) "); //照度指数
    scanf("%lf", &x[2]);
    p[2] = (1.0 / 5.0) * (104.0 - 2.0 * ((x[2] / 20.0) + (20.0 / x[2])));
    printf("Noise Point(db) "); //静けさ指数
    scanf("%lf", &x[3]);
    double t;
    if (x[3] < 20 && x[3] >= 0)
        p[3] = 20.0;
    else if (x[3] < 70 && x[3] >= 20){
        t = 100.0 - 2.0 * (x[3] - 20.0);
        p[3] = 30.0 - (1000.0 / t);
    }else
        p[3] = -INFINITY;
    printf("Look up each other silence times "); //見つめ合い指数
    scanf("%lf", &x[4]);
    double S;
    if(x[4] < 30 && x[4] > 0)
        S = (100.0 / 30.0) * x[4];
    else if (x[4] <= 60 && x[4] >= 30)
        S = 100.0;
    else
        S = 100.0 - 5.0 * (x[4] - 60.0);
    p[4] = (1.0 / 5.0) * S;
    for (int i = 0; i < 5; i++)
        MoodPoint += p[i];
    for (int i = 0; i < 5; i++)
        printf("p[%d] = %.1lf\n",i + 1,p[i]);
    puts("---------");
    printf("MoodPoint \n%.1lf\n",MoodPoint);
    return 0;
}

