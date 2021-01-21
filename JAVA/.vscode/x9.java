public class x9 
{
    public static void main(String[] args)
    {
        int i,j;
        for(i=1;i<=9;i++)
        {
           for(j=1;j<=9;j++)
           {
               System.out.println(i+"*"+j+"="+i*j);
           }
           extracted();
        }    
    }

    private static void extracted() {
        System.out.println("\n");
    }    
}
