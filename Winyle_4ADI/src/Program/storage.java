package Program;
import java.io.*;
import java.util.ArrayList;

public class storage extends disc
{
	protected ArrayList<vinyl> vinyls;
	protected ArrayList<vinyl> trash;
	protected ArrayList<vinyl> found;
	protected ArrayList <Integer> indexes;
	protected int quantity;
	protected int quantityTrash;
	protected int quantityFound;
	protected int current;
	protected int currentTrash;
	protected int currentFound;
	protected String secret;
	protected String password;
	
	public storage()
	{
		vinyls = new ArrayList<>();
		trash = new ArrayList<>();
		found = new ArrayList<>();
		indexes = new ArrayList<>();
		quantity=0;
		current=-1;
		quantityFound=0;
		currentFound=-1;
		quantityTrash=0;
		currentTrash=-1;
	}
	
	public storage(int n)
	{
		vinyls = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			vinyls.add(new vinyl());
		}
		trash = new ArrayList<>();
		found = new ArrayList<>();
		indexes = new ArrayList<>();
		quantity=0;
		current=-1;
		quantityFound=0;
		currentFound=-1;
		quantityTrash=0;
		currentTrash=-1;
	}
	
	public void setPassword(String pass)
	{
		password=pass;
	}
	
	public String getPassword()
	{
		return password;
	}
	
	public int getQuantity()
	{
		return quantity;
	}
	
	public int getQuantityFound()
	{
		return quantityFound;
	}
	
	public int getQuantityTrash()
	{
		return quantityTrash;
	}
	

	public int getCurrent()
	{
		return current;
	}
	
	public int getCurrentFound()
	{
		return currentFound;
	}
	
	public int getCurrentTrash()
	{
		return currentTrash;
	}
	
	public vinyl getTab() 
	{
	    return vinyls.get(current); 
	}
	
	public void next() 
	{
		if(current<quantity-1)
			current++;
	}


	public void previous() 
	{
		if(current>0)
			current--;
	}
	
	public void deleteCurrentVinyl(int i) 
	{
		found.clear();
		indexes.clear();
		currentFound=-1;
		quantityFound=0;
		trash.add(vinyls.get(current));
		quantityTrash++;
		if(currentTrash==-1)
			currentTrash=0;
		if(quantity>=1)
		{
			vinyls.remove(current);
			if(current==quantity-1)
				current--;
			quantity--;
		}
	}
	
	public void sortPrice()
	{
		vinyl pom;
		for(int nr=1; nr<quantity; nr++)
			for(int i=0; i<quantity-nr; i++)
				if(vinyls.get(i).getPrice()>vinyls.get(i+1).getPrice())
				{
					pom=vinyls.get(i);
					vinyls.set(i, vinyls.get(i+1));
					vinyls.set(i+1, pom);
				}
	}
	
	public void sortArtist() 
	{
	    vinyl pom;
	    for (int nr = 1; nr < quantity; nr++) 
	    {
	        for (int i = 0; i < quantity - nr; i++) 
	        {
	            if (vinyls.get(i).getSurname().compareToIgnoreCase(vinyls.get(i+1).getSurname()) > 0) 
	            {
	            	
	                pom = vinyls.get(i);
	                vinyls.set(i, vinyls.get(i + 1));
	                vinyls.set(i + 1, pom);
	            }
	            else
	            {
	            	if(vinyls.get(i).getName().compareToIgnoreCase(vinyls.get(i+1).getSurname()) > 0)
	            	{
	            		pom = vinyls.get(i);
		                vinyls.set(i, vinyls.get(i + 1));
		                vinyls.set(i + 1, pom);
	            	}
	            }
	        }
	    }
	}

	public void sortDate() 
	{
	    vinyl pom;
	    for (int nr = 1; nr < quantity; nr++) 
	    {
	        for (int i = 0; i < quantity - nr; i++) 
	        {
	            if (vinyls.get(i).getYear() > vinyls.get(i + 1).getYear() || 
	                (vinyls.get(i).getYear() == vinyls.get(i + 1).getYear() && vinyls.get(i).getMonth() > vinyls.get(i + 1).getMonth()) ||
	                (vinyls.get(i).getYear() == vinyls.get(i + 1).getYear() && vinyls.get(i).getMonth() == vinyls.get(i + 1).getMonth() && vinyls.get(i).getDay() > vinyls.get(i + 1).getDay())) 
	            {
	                pom = vinyls.get(i);
	                vinyls.set(i, vinyls.get(i + 1));
	                vinyls.set(i + 1, pom);
	            }
	        }
	    }
	}
	
	public int addNewVinyl(String ty, String dist, double pr, int d, int m, int y, String ttl, String nam, String sur, double rm, String edt)
	{
		vinyl nowy = new vinyl();
		nowy.set(ty, dist, pr, d, m, y, ttl, nam, sur, rm, edt);
		vinyls.add(nowy);
		quantity++;
		if(current==-1)
			current=0;
		return 0;
	}
	
	public void clearVinyls()
	{
		vinyls.clear();
		quantity=0;
	}
	
	public vinyl getVinyl(int i)
	{
		return vinyls.get(i);
	}
	
	public vinyl getVinylTrash(int i)
	{
		return trash.get(i);
	}
	
	public void nextTrash()
	{
		if(currentTrash<quantityTrash-1)
			currentTrash++;
	}


	public void previousTrash()
	{
		if(currentTrash>0)
			currentTrash--;
	}


	public void deleteCurrentTrash()
	{
		trash.remove(currentTrash);
		if(currentTrash==quantityTrash-1)
			currentTrash--;
		quantityTrash--;
	}
			

	public void deleteAllTrash()
	{
		currentTrash=quantityTrash-1;
		int q=quantityTrash;	
		for(int i=q; i>0; i--)
		{
			trash.remove(currentTrash);
			currentTrash--;
			quantityTrash--;
		}
											

	}
	public void addBackTrash()
	{
		vinyls.add(trash.get(currentTrash));
		quantity++;
		if(current==-1)
			current=0;
		trash.remove(currentTrash);
		if(currentTrash==quantityTrash-1)
			currentTrash--;
		quantityTrash--;
	}
	
	public int searchRPM(double sRPM)
	{
		quantityFound=0;
		currentFound=-1;
		found.clear();
		for(int i=0; i<quantity; i++)
		{
			if(vinyls.get(i).getRPM()==sRPM)
			{
				found.add(vinyls.get(i));
				indexes.add(i);
				quantityFound++;
			}
		}
		if (quantityFound>0)
		{
			currentFound=0;
			return 1;
		}
		else
			return 0;
	}
	
	public int searchPrice(double min, double max)
	{
		quantityFound=0;
		currentFound=-1;
		found.clear();
		if(min<=0)
			return 2;
		else if(max>=2000000)
			return 3;
		else if(min>max)
			return 4;
		else if(max<min)
			return 5;
		else
		{
			for(int i=0; i<quantity; i++)
			{
				if(vinyls.get(i).getPrice()>=min && vinyls.get(i).getPrice()<=max)
				{
					found.add(vinyls.get(i));
					indexes.add(i);
					quantityFound++;
				}
			}
			if (quantityFound>0)
			{
				currentFound=0;
				return 1;
			}
			else
				return 0;	
		}
	}


	public int searchSurname(String sSurname)
	{
		quantityFound=0;
		currentFound=-1;
		found.clear();
		for (int i=0; i<quantity; i++)
		{
			if (vinyls.get(i).getSurname().equalsIgnoreCase(sSurname))
			{
				found.add(vinyls.get(i));
				indexes.add(i);
				quantityFound++;
			}
		}
		if (quantityFound>0)
		{
			currentFound=0;
			return 1;
		}
		else
			return 0;
	}


	public int searchArtist(String sName, String sSurname)
	{
		quantityFound=0;
		currentFound=-1;
		found.clear();
		for (int i=0; i<quantity; i++)
		{
			if (vinyls.get(i).getSurname().equalsIgnoreCase(sSurname) || vinyls.get(i).getName().equalsIgnoreCase(sName))
			{
				found.add(vinyls.get(i));
				indexes.add(i);
				quantityFound++;
			}
		}
		if (quantityFound>0)
		{
			currentFound=0;
			return 1;
		}
		else
			return 0;
	}
	

	public int searchTitleAlphabet(char zn)
	{
		quantityFound=0;
		currentFound=-1;
		found.clear();
		for (int i=0; i<quantity; i++)
		{
			if(Character.toLowerCase(vinyls.get(i).getTitle().charAt(0)) == Character.toLowerCase(zn))
			{
				found.add(vinyls.get(i));
				indexes.add(i);
				quantityFound++;
			}
		}
		if (quantityFound>0)
		{
			currentFound=0;
			return 1;
		}
		else
			return 0;
		
	}
	
	
	public vinyl getVinylFound(int i)
	{
		return found.get(i);
	}


	public vinyl getFound()
	{
		return found.get(currentFound);
	}

	public void nextFound()
	{
		if(currentFound<quantityFound-1)
			currentFound++;
	}


	public void previousFound()
	{
		if(currentFound>0)
			currentFound--;
	}


	public void deleteCurrentFound()
	{
		trash.add(found.get(currentFound));
		quantityTrash++;
		if(currentTrash==-1)
			currentTrash=0;
		found.remove(currentFound);
		indexes.remove(currentFound);
		if(current==quantity-1)
			current--;
		quantity--;
		if(currentFound>=1)
		{
			found.remove(currentFound);
			if(currentFound==quantityFound-1)
				currentFound--;
			quantityFound--;
		}
		int q=quantityFound;
		if(currentFound<quantityFound-1)
		{
			for(int i=0;i<q;i++)
			{
				indexes.set(i, indexes.get(i - 1));
			}
		}
	}

	public void deleteAllFound()
	{
		currentFound=quantityFound-1;
		int q=quantityFound;	
		for(int i=q; i>0; i--)
		{
			trash.add(found.get(currentFound));
			quantityTrash++;
			if(currentTrash==-1)
				currentTrash=0;
			vinyls.remove((int) indexes.get(currentFound));
			indexes.remove(currentFound);
			if(current==quantity-1)
				current--;
			quantity--;
			found.remove(currentFound);
			if(currentFound==quantityFound-1)
				currentFound--;
			quantityFound--;
		}
	}
	
	public int changeArtist(String oldName, String oldSurname, String Name, String Surname)
	{
		int j=0;
		for(int i=0; i<quantity; i++)
		{
			if ( vinyls.get(i).getName().equalsIgnoreCase(oldName) || vinyls.get(i).getSurname().equalsIgnoreCase(oldSurname))
			{
				vinyls.get(i).setName(Name);
				vinyls.get(i).setSurname(Surname);	
				j++;
			}
		}
		if(j==0)
			return 1;
		return 0;
	}


	public int changePricePercent(double percent, double min, double max)
	{
		int j=0;
		
		if(min<=0)
			return 1;
		else if(max>=2000000)
			return 2;
		else if(min>max)
			return 3;
		else if(percent<-100)
			return 4;
		else if(percent>200)
			return 5;
		for(int i=0; i<quantity; i++)
		{
			if(vinyls.get(i).getPrice()>=min && vinyls.get(i).getPrice()<=max)
			{
				vinyls.get(i).setPrice(vinyls.get(i).getPrice()+(vinyls.get(i).getPrice() * percent/100));
				j++;
			}
		}
		if(j==0)
			return 6;
		return 7;
	}


	public int changePricePercentExact(double percent, double oldPrice)
	{
		int j=0;
		
		for(int i=0; i<quantity; i++)
		{
			if(vinyls.get(i).getPrice()==oldPrice)
			{
				vinyls.get(i).setPrice(vinyls.get(i).getPrice()+(vinyls.get(i).getPrice() * percent/100));
				j++;
			}
		}
		if(j==0)
			return 0;
		return 1;
		
	}
			
		
	public int changePriceNumber(double newPrice, double min, double max)
	{
		int j=0;
		
		if(min<=0)
			return 1;
		else if(max>=2000000)
			return 2;
		else if(min>max)
			return 3;
		else if(newPrice<0)
			return 4;
		else if(newPrice>2000000)
			return 5;
		for(int i=0; i<quantity; i++)
		{
			if(vinyls.get(i).getPrice()>=min && vinyls.get(i).getPrice()<=max)
			{
				vinyls.get(i).setPrice(newPrice);
				j++;
			}
		}
		if(j==0)
			return 6;
		return 7;
	}


	public int changePriceNumberExact(double newPrice, double oldPrice)
	{	
		int j=0;
		for(int i=0; i<quantity; i++)
		{
			if(vinyls.get(i).getPrice()==oldPrice)
			{
				vinyls.get(i).setPrice(newPrice);
				j++;
			}
		}
		if(j==0)
			return 0;
		return 1;	
	}
	
// Funkcja do maskowania hasła
	private static String obfuscate(String pass) 
	{
        String secret = ""; 
        String letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Zestaw liter

        for (int i = 0; i < pass.length(); i++) 
        {
            char c = pass.charAt(i);  
            secret += c;  
            int randomIndex = (int) (Math.random() * letters.length());
            char randomChar = letters.charAt(randomIndex); 
            secret += randomChar;  
        }

        return secret;  
    }

    // Funkcja do demaskowania hasła
    private static String deobfuscate(String sec) 
    {
        String original = ""; 

        for (int i = 0; i < sec.length(); i += 2) 
        {
            original += sec.charAt(i);  
        }

        return original;  
    }

	public void saveToFile()
	{
		FileOutputStream writeStream=null;
		File data=new File("discs.dat");
		
		try
		{
			writeStream= new FileOutputStream(data);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File does not exist " + e);	//powinno byc do klasy obslugujacej
			System.exit(-1);
		}
		
		DataOutputStream ws=new DataOutputStream(writeStream);
		try
		{
			ws.writeInt(quantity);
		}
		catch(IOException e)
		{
			System.err.println("Failed to save elements" + e);
			System.exit(-1);
		}
		
		for (int i=0; i<quantity; i++)
		{
			try
			{
				ws.writeUTF(vinyls.get(i).type);
				ws.writeUTF(vinyls.get(i).distributor);
				ws.writeDouble(vinyls.get(i).price);
				ws.writeInt(vinyls.get(i).day);
				ws.writeInt(vinyls.get(i).month);
				ws.writeInt(vinyls.get(i).year);
				ws.writeUTF(vinyls.get(i).getTitle());
				ws.writeUTF(vinyls.get(i).getName());
				ws.writeUTF(vinyls.get(i).getSurname());
				ws.writeDouble(vinyls.get(i).getRPM());
				ws.writeUTF(vinyls.get(i).getEdition());
			}
			catch (IOException e)
			{
				System.err.println("Failed to save element " + i + "Exception " + e);
				System.exit(-1);
			}
		}
		
		try
		{
			ws.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the write stream" + e);
			System.exit(-1);
		}
		
		try
		{
			writeStream.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the write stream" + e);
			System.exit(-1);
		}
	}
	
	public void readFromFile()
	{
		FileInputStream readStream=null;
		File data=new File("discs.dat");
		
		try
		{
			readStream= new FileInputStream(data);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File does not exist " + e);	
			System.exit(-1);
		}
		
		DataInputStream rs=new DataInputStream(readStream);
		try
		{
			quantity=rs.readInt();
			current=0;
		}
		catch(IOException e)
		{
			System.err.println("Failed to read elements" + e);
			System.exit(-1);
		}
		
		for (int i=0; i<quantity; i++)
		{
			try
			{
				vinyl v = new vinyl();
		        v.type = rs.readUTF();
		        v.distributor = rs.readUTF();
		        v.price = rs.readDouble();
		        v.day = rs.readInt();
		        v.month = rs.readInt();
		        v.year = rs.readInt();
		        v.setTitle(rs.readUTF());
		        v.setName(rs.readUTF());
		        v.setSurname(rs.readUTF());
		        v.setRPM(rs.readDouble());
		        v.setEdition(rs.readUTF());
		        vinyls.add(v);
			}
			catch (IOException e)
			{
				System.err.println("Failed to read element " + i + "Exception " + e);
				System.exit(-1);
			}
		}
		
		try
		{
			rs.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the read stream" + e);
			System.exit(-1);
		}
		
		try
		{
			readStream.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the read stream" + e);
			System.exit(-1);
		}
	}
	
	public void saveToFileTrash()
	{
		FileOutputStream writeStream=null;
		File data=new File("trash.dat");
		
		try
		{
			writeStream= new FileOutputStream(data);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File does not exist " + e);	
			System.exit(-1);
		}
		
		DataOutputStream ws=new DataOutputStream(writeStream);
		try
		{
			ws.writeInt(quantityTrash);
		}
		catch(IOException e)
		{
			System.err.println("Failed to save elements" + e);
			System.exit(-1);
		}
		
		for (int i=0; i<quantityTrash; i++)
		{
			try
			{
				ws.writeUTF(trash.get(i).type);
				ws.writeUTF(trash.get(i).distributor);
				ws.writeDouble(trash.get(i).price);
				ws.writeInt(trash.get(i).day);
				ws.writeInt(trash.get(i).month);
				ws.writeInt(trash.get(i).year);
				ws.writeUTF(trash.get(i).getTitle());
				ws.writeUTF(trash.get(i).getName());
				ws.writeUTF(trash.get(i).getSurname());
				ws.writeDouble(trash.get(i).getRPM());
				ws.writeUTF(trash.get(i).getEdition());
			}
			catch (IOException e)
			{
				System.err.println("Failed to save element " + i + "Exception " + e);
				System.exit(-1);
			}
		}
		
		try
		{
			ws.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the write stream" + e);
			System.exit(-1);
		}
		
		try
		{
			writeStream.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the write stream" + e);
			System.exit(-1);
		}
	}
	public int readFromFileTrash()
	{
		FileInputStream readStream=null;
		File data=new File("trash.dat");
		
		try
		{
			readStream= new FileInputStream(data);
		}
		catch (FileNotFoundException e)
		{
			return 1;
		}
		
		DataInputStream rs=new DataInputStream(readStream);
		try
		{
			quantityTrash=rs.readInt();
			currentTrash=0;
		}
		catch(IOException e)
		{
			System.err.println("Failed to read elements" + e);
			System.exit(-1);
		}
		
		for (int i=0; i<quantityTrash; i++)
		{
			try
			{
				vinyl v = new vinyl();
		        v.type = rs.readUTF();
		        v.distributor = rs.readUTF();
		        v.price = rs.readDouble();
		        v.day = rs.readInt();
		        v.month = rs.readInt();
		        v.year = rs.readInt();
		        v.setTitle(rs.readUTF());
		        v.setName(rs.readUTF());
		        v.setSurname(rs.readUTF());
		        v.setRPM(rs.readDouble());
		        v.setEdition(rs.readUTF());
		        trash.add(v);
			}
			catch (IOException e)
			{
				System.err.println("Failed to read element " + i + "Exception " + e);
				System.exit(-1);
			}
		}
		
		try
		{
			rs.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the read stream" + e);
			System.exit(-1);
		}
		
		try
		{
			readStream.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the read stream" + e);
			System.exit(-1);
		}
		return 0;
	}
	
	public void savePass()
	{
		FileOutputStream writeStream=null;
		File data=new File("password.txt");
		
		secret=obfuscate(password);
		
		try
		{
			writeStream= new FileOutputStream(data);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File does not exist " + e);	
			System.exit(-1);
		}
		
		DataOutputStream ws=new DataOutputStream(writeStream);
		try
		{
			ws.writeUTF(secret);
		}
		catch(IOException e)
		{
			System.err.println("Failed to save password" + e);
			System.exit(-1);
		}
		
		try
		{
			ws.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the write stream" + e);
			System.exit(-1);
		}
		
		try
		{
			writeStream.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the write stream" + e);
			System.exit(-1);
		}
	}
	public int readPass()
	{
		FileInputStream readStream=null;
		File data=new File("password.txt");
		
		try
		{
			readStream= new FileInputStream(data);
		}
		catch (FileNotFoundException e)
		{
			return 1;
		}
		
		DataInputStream rs=new DataInputStream(readStream);
		try
		{
			secret=rs.readUTF();
		}
		catch(IOException e)
		{
			System.err.println("Failed to read elements" + e);
			System.exit(-1);
		}
		
		try
		{
			rs.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the read stream" + e);
			System.exit(-1);
		}
		
		try
		{
			readStream.close();
		}
		catch(IOException e)
		{
			System.err.println("Failed to close the read stream" + e);
			System.exit(-1);
		}
		password=deobfuscate(secret);
		return 0;
	}
}
