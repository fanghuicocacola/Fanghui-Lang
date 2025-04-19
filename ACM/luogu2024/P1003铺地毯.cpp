#include<iostream>
typedef struct 
{
    int a;
    int b;
    int g;
    int k;
}Carpet;

int main()
{
    int n,x,y;
    //第一行，一个整数n，表示总共有n张地毯
    std::cin>>n; 
    Carpet carpets[n];
    //初始化时，任一点没有被覆盖
    for(int i = 0;i < n;i++)
    {
        //分别表示铺设地毯的左下角的坐标 (𝑎,𝑏) 以及地毯在 𝑥 轴和 𝑦 轴方向的长度。
        std::cin>>carpets[i].a>>carpets[i].b>>carpets[i].g>>carpets[i].k;
        
    }
    //表示所求的地面的点的坐标 (𝑥,𝑦)
    std::cin>>x>>y;
    int on_carpet = -1;
    for(int i = n-1;i >= 0;i--)
    {
        if (x >= carpets[i].a && x <= carpets[i].a + carpets[i].g && y >= carpets[i].b && y <= carpets[i].b + carpets[i].k) 
        {
            on_carpet = i + 1;
            break;
        }
    }
    std::cout<<on_carpet;
}
