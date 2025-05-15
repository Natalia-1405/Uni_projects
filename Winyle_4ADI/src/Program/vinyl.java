package Program;

public class vinyl extends disc
{
	private String title;
	private String name;
	private String surname;
	private double rpm;
	private String edition;
	
	public vinyl()
	{
		super();
		title="";
		name="";
		surname="";
		rpm=0;
		edition="";
	}
	
	public vinyl(String ty, String dist, double pr, int d, int m, int y, String ttl, String nam, String sur, int rm, String edt)
	{
		super(ty,dist,pr,d,m,y);
		title=ttl;
		name=nam;
		surname=sur;
		rpm=rm;
		edition=edt;
	}

	public void clear()
	{
		super.clear();
		title="";
		name="";
		surname="";
		rpm=0;
		edition="";
	}
	
	public void set (String ty, String dist, double pr, int d, int m, int y, String ttl, String nam, String sur, double rm, String edt)
	{
		type=ty;
		distributor=dist;
		price=pr;
		day=d;
		month=m;
		year=y;
		title=ttl;
		name=nam;
		surname=sur;
		rpm=rm;
		edition=edt;
	}
	
	public void setTitle(String ttl)
	{
		if(ttl.length() > 40)
         	ttl = ttl.substring(0, 40);
		title=ttl;
	}
	
	public void setName(String nam)
	{
		if(nam.length() > 50) 
        	nam = nam.substring(0, 50);
		name=nam;
	}
	
	public void setSurname(String sur)
	{
		 if(sur.length() > 40)
	     		sur = sur.substring(0, 40);
		surname=sur;
	}
	
	public int setRPM(double rm)
	{
		if(rm==33 || rm==45 || rm==78 || rm==33.3)
		{
			rpm=rm;
			return 0;
		}
		return 1;
	}
	
	public void setEdition(String edt)
	{
		 if(edt.length() > 40)
	         	edt = edt.substring(0, 40);
		edition=edt;
	}
	
	public String getTitle()
	{
		return title;
	}
	
	public String getName()
	{
		return name;
	}
	
	public String getSurname()
	{
		return surname;
	}
	
	public double getRPM()
	{
		return rpm;
	}
	
	public String getEdition()
	{
		return edition;
	}
	
}

