#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void yellow()
{
	printf("\x1b[33m");
}
void cyan()
{
	printf("\x1b[36m");
}
void green()
{
	printf("\x1b[32m");
}
void reset()
{
	printf("\x1b[0m");
}

int yr(int ye,int mo,int da,int ye1,int mo1,int da1)
{
	int c=0;
	if(ye>=ye1)
	    c=0;
	else
	{
	    ++ye;
	    for(;ye<ye1;ye++)
		    ++c;
	    if(mo<mo1)
		    ++c;
	    else if(mo==mo1)
	    {
		    if(da<=da1)
			    ++c;
	    }
	}
	return c;
}

int year(int ye,int mo,int da,int ye1,int mo1,int da1)
{
	int c=0;
	if(ye==ye1)
	    c=0;
	else if(ye>ye1)
	{
	    for(;ye>ye1;ye--)
	        --c;
	    if(mo<mo1)
	        ++c;
	}
	else
	{
	    ++ye;
	    for(;ye<ye1;ye++)
		    ++c;
	    if(mo<mo1)
		    ++c;
	    else if(mo==mo1)
	    {
		    if(da<=da1)
			    ++c;
	    }
	}
	return c;
}

int month(int ye,int mo,int da,int ye1,int mo1,int da1)
{
	int c=0;
	int mo2=mo;
	if((ye==ye1) && (mo>=mo1))
	{
	    for(;mo>mo1;mo--)
	        c--;
	}
	else if(ye>ye1)
    {
        c=(-12)*(ye-ye1);
        if(mo>=mo1)
        {
            for(;mo>mo1;mo--)
                --c;
        }
        else
        {
            for(;mo<mo1;mo++)
                c++;
        }
    }
	else if((ye==ye1) && (mo<mo1))
	{
	    for(;mo2<mo1;mo2++)
		    ++c;
	}
	else
	{
	    ++ye;
	    for(;mo2<12;mo2++)
		    ++c;
	    if(mo2==12)
		    mo2=1;
	    for(;ye<ye1;ye++)
		    c+=12;
	    if(mo>mo1 && mo<=12){
	        if(da<=da1)
	            c++;
	    }
	    else if(mo<=mo1){
	        if(da<=da1)
	            c++;
	    }
	    for(;mo2<mo1;mo2++)
		    ++c;
	}
	return c;
}

int days(int ye,int mo,int da,int ye1,int mo1,int da1)
{
	int c=0;
	if(ye==ye1 && mo==mo1) 
	{
	    if(da>=da1)
	       c=da1-da;
	    else
	       c=da1-da;
	}
	else if(ye==ye1 && mo>mo1)
	{
	    for(;mo>mo1;mo--)
	    {
	        if(mo<=7)
		    {
			    if(mo%2==0)
			    {
				    if(mo==2)
				    {
					    if((ye%4==0 && ye%100!=0) || ye%400==0)
						    c-=29;
					    else
						    c-=28;
				    }
				    else
					    c-=30;
			    }
			    else
				    c-=31;
		    }
		    else
		    {
			    if(mo%2==0)
				    c-=31;
			    else
			    	c-=30;
		    }
	    }
	     if(da>da1)
            {
                for(;da>da1;da--)
                    --c;
            }
            else
            {
                for(;da<da1;da++)
                    ++c;
            }
	}
	else if(ye==ye1 && mo<mo1) 
	{
	    if(mo<=7)
	    {
		    if(mo%2==0)
		    {
			    if(mo==2)
			    {
				    if((ye%4==0 && ye%100!=0) || ye%400==0)
					    c=29-da;
				    else
					    c=28-da;
			    }
			    else
				    c=30-da;
		    }
		    else
			    c=31-da;
	    }
	    else
	    {
		    if(mo%2==0)
			    c=31-da;
		    else
			    c=30-da;
	    }
	    ++mo;
	    for(;mo<mo1;mo++)
	    {
		    if(mo<=7)
		    {
			    if(mo%2==0)
			    {
				    if(mo==2)
				    {
					    if((ye%4==0 && ye%100!=0) || ye%400==0)
						    c+=29;
					    else
						    c+=28;
				    }
				    else
					    c+=30;
			    }
			    else
				    c+=31;
		    }
		    else
		    {
			    if(mo%2==0)
				    c+=31;
			    else
			    	c+=30;
		    }
	    }
	    c+=da1;
	}
	else if(ye>ye1)
    {
        int y=ye;
        for(;ye>ye1;ye--)
        {
            if((ye%4==0 && ye%100!=0) || ye%400==0)
                c-=366;
            else
                c-=365;
        }
        if(mo>mo1)
        {
            for(;mo>mo1;mo--){
            if(mo<=7)
		    {
			    if(mo%2==0)
			    {
				    if(mo==2)
				    {
					    if((y%4==0 && y%100!=0) || y%400==0)
						    c-=29;
					    else
						    c-=28;
				    }
				    else
					    c-=30;
			    }
			    else
				    c-=31;
		    }
		    else
		    {
			    if(mo%2==0)
				    c-=31;
			    else
			    	c-=30;
		    }
            }
        }
        else if(mo<mo1)
        {
            for(;mo<mo1;mo++){
            if(mo<=7)
		    {
			    if(mo%2==0)
			    {
				    if(mo==2)
				    {
					    if((y%4==0 && y%100!=0) || y%400==0)
						    c+=29;
					    else
						    c+=28;
				    }
				    else
					    c+=30;
			    }
			    else
				    c+=31;
		    }
		    else
		    {
			    if(mo%2==0)
				    c+=31;
			    else
			    	c+=30;
		    }
            }
        }
        if(da>da1)
            {
                for(;da>da1;da--)
                    --c;
            }
            else
            {
                for(;da<da1;da++)
                    ++c;
            }
    }
	else{
	if(mo<=7)
	{
		if(mo%2==0)
		{
			if(mo==2)
			{
				if((ye%4==0 && ye%100!=0) || ye%400==0)
					c=29-da;
				else
					c=28-da;
			}
			else
				c=30-da;
		}
		else
			c=31-da;
	}
	else
	{
		if(mo%2==0)
			c=31-da;
		else
			c=30-da;
	}
	++mo;
	for(;mo<=12;mo++)
	{
		if(mo<=7)
		{
			if(mo%2==0)
			{
				if(mo==2)
				{
					if((ye%4==0 && ye%100!=0) || ye%400==0)
						c+=29;
					else
						c+=28;
				}
				else
					c+=30;
			}
			else
				c+=31;
		}
		else
		{
			if(mo%2==0)
				c+=31;
			else
				c+=30;
		}
	}
	if(mo>12)
		mo=1;
	++ye;
	for(;ye<ye1;ye++)
	{
		if((ye%4==0 && ye%100!=0) || ye%400==0)
			c+=366;
		else
			c+=365;
	}
	for(;mo<mo1;mo++)
	{
		if(mo<=7)
		{
			if(mo%2==0)
			{
				if(mo==2)
				{
					if((ye1%4==0 && ye1%100!=0) || ye1%400==0)
						c+=29;
					else
						c+=28;
				}
				else
					c+=30;
			}
			else
				c+=31;
		}
		else
		{
			if(mo%2==0)
				c+=31;
			else
				c+=30;
		}
	}
	c+=da1;
	    
	}
	return c;
}

void extra(int ye,int mo,int da,int ye1,int mo1,int da1)
{
	printf("-------------------------------------------\n");
	yellow();
	printf("Total no. of Years  : %d\n",year(ye,mo,da,ye1,mo1,da1));
	printf("Total no. of Months : %d\n",month(ye,mo,da,ye1,mo1,da1));
	printf("Total no. of Days   : %d\n",days(ye,mo,da,ye1,mo1,da1));
 	reset();
	printf("-------------------------------------------\n");	
}

void YDM(int ye,int mo,int da,int ye1,int mo1,int da1)
{
	int ye2=yr(ye,mo,da,ye1,mo1,da1);
	int mo2,mo3,co=0,cou=0;
	mo2=mo;mo3=mo1;
	if(mo==mo1)
	{
	    if(da>da1)
	        co=11;
	    else
	        co=0;
	}
	else if(mo2>mo3)
	{
		for(;mo2<12;++mo2)
			++co;
		if(mo2==12)
			mo2=1;
		for(;mo2<=mo3;mo2++)
			++co;
		if(da>da1)
		    --co;
	}
	else
	{
		for(;mo2<mo3;mo2++)
			++co;
		if(da>da1)
		    --co;
	}
	if(da==da1)
		cou=0;
	else
	{
		mo2=mo1-1;
		if(mo2<=7)
		{
			if(mo2%2==0)
			{
				if(mo2==2)
				{
					if((ye1%4==0 && ye1%100!=0) || ye1%400==0)
					{
						cou=29-da;
						cou+=da1;
						if(cou>=29)
							cou-=29;
					}
					else
					{
						cou=28-da;
						cou+=da1;
						if(cou>=28)
							cou-=28;
					}
				}
				else
				{
					cou=30-da;
					cou+=da1;
					if(cou>=30)
						cou-=30;
				}
			}
			else
			{
				cou=31-da;
				cou+=da1;
				if(cou>=31)
					cou-=31;
			}
		}
		else
		{
			if(mo2%2==0)
			{
				cou=31-da;
				cou+=da1;
				if(cou>=31)
					cou-=31;
			}
			else
			{
				cou=30-da;
				cou+=da1;
				if(cou>=30)
					cou-=30;
			}
		}
	}
	printf("-------------------------------------------\n");
	yellow();
	printf("You are %d years, %d months and %d days old.\n",ye2,co,cou);
 	reset();
	printf("-------------------------------------------\n");			
}

void print(int day,int month,int year)
{
    printf("-------------------------------------------\n");
	yellow();
	printf("%d-%d-%d\n",day,month,year);
 	reset();
	printf("-------------------------------------------\n");
}
int main() 
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int y1,m1,d1,y,m,d,ch;
	y1=tm.tm_year+1900;
	m1=tm.tm_mon+1;		
	d1=tm.tm_mday;
	green();
	printf("Enter your choice: \n1: To know your age in years, months and days\n2: To know your age in years only.\n3: To exit\n");
	scanf("%d",&ch);
	reset();
	while(ch!=3)
	{
	    green();
	    printf("Please enter your Date of Birth in date,month and year: ");
	    scanf("%d %d %d",&d,&m,&y);
	    cyan();
	    printf("\n\nCurrent Date\n");
	    reset();
	    print(d1,m1,y1);
	    cyan();
	    printf("\nDate of Birth\n");
    	reset();
	    print(d,m,y);
	    reset();
	    cyan();
	    printf("\nAge\n");
	    reset();
	    if((y==y1 && m==m1) && d>d1)
	    {
	        printf("-------------------------------------------\n");
	        yellow();
	        printf("You are not born yet\n");
 	        reset();
	        printf("-------------------------------------------\n");
	    
	    }
	    else if((y==y1 && m>m1) && (d>=d1 || d<d1))
	    {
	        printf("-------------------------------------------\n");
	        yellow();
	        printf("You are not born yet\n");
 	        reset();
	        printf("-------------------------------------------\n");
	    }
	    else if((y>y1 && (m>=m1 || m<m1)) && (d>=d1 || d<d1))
	    {
	        printf("-------------------------------------------\n");
	        yellow();
	        printf("You are not born yet\n");
 	        reset();
	        printf("-------------------------------------------\n");
	    }
	    else
	    {
	        if(ch==1)
	            YDM(y,m,d,y1,m1,d1);
	         else
	        {
	        printf("-------------------------------------------\n");
	        yellow();
	        printf("You are %d years old.\n",yr(y,m,d,y1,m1,d1));
 	        reset();
	        printf("-------------------------------------------\n");	
	        }
	    }
	    cyan();
	    printf("\nExtra\n");
	    reset();
	    extra(y,m,d,y1,m1,d1);
	    green();
	    printf("Want to try again, then please enter your choice: \n1: To know your age in years, months and days.\n2: To know your age in years only.\n3: To exit\n");
	    scanf("%d",&ch);
	    reset();
	    system("clear"); 
	}
	return 0;
}