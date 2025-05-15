package Program;

public class disc 
{
	protected String type;
	protected String distributor;
	protected double price;
	protected int day;
	protected int month;
	protected int year;
	
	public disc()
	{
		type="";
		distributor="";
		price=0;
		day=0;
		month=0;
		year=0;
	}
	
	public disc(String ty, String dist, double pr, int d, int m, int y)
	{
		type=ty;
		distributor=dist;
		price=pr;
		day=d;
		month=m;
		year=y;
	}
	
	public void clear()
	{
		type="";
		distributor="";
		price=0;
		day=0;
		month=0;
		year=0;
	}
	
	public void set(String ty, String dist, double pr, int d, int m, int y)
	{	
		type=ty;
		distributor=dist;
		price=pr;
		day=d;
		month=m;
		year=y;
	}
	
	public void setType(String ty)
	{	
		type=ty;
	}
	
	public void setDist(String dist)
	{	
		 if(dist.length() > 40)
	         	dist = dist.substring(0, 40);
		distributor=dist;
	}
	
	public int setPrice(double pr)
	{	
		if (pr>0.01 && pr<180000) 
		{
			price=pr;
			return 0;
		}
		else
			return 1;
	}
	
	public int setDate(int y, int m, int d)
	{
		if (y>=1930 && y<=2025) 
			year=y;
		else
		{
			year=0;
			month=0;
			day=0;
			return 1;
		}
		
		if(m>=1 && m<=12)
			month=m;
		else
		{
			month=0;
			day=0;
			return 2;
		}	
		
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
		{
			if (d>=1 && d<=31)
				day=d;
			else
			{
				day=0;
				return 3;
			}
		}
		else if(m==2)
		{
			if((y%4==0 && y%100!=0)|| y%400==0)
			{
				if(d>=1 && d<=29)
					day=d;
				else
				{
					day=0;
					return 4;
				}
			}
			else
			{
				if(d>=1 && d<=28)
				
					day=d;
				else
				{	
					day=0;
					return 5;
				}
			}
		}
		else
		{
			if (d>=1 && d<=30)
				day=d;
			else
			{
				day=0;
				return 6;
			}	
		}	
			
		return 0;
	}
	
	public void setDay(int d)
	{	
		day=d;
	}
	
	public void setMonth(int m)
	{	
		month=m;
	}
	
	public void setYear(int y)
	{	
		year=y;
	}
	
	public String getType()
	{
		return type;
	}
	
	public String getDist()
	{
		return distributor;
	}
	
	public double getPrice()
	{
		return price;
	}
	
	public int getDay()
	{
		return day;
	}
	
	public int getMonth()
	{
		return month;
	}
	
	public int getYear()
	{
		return year;
	}
	
}
