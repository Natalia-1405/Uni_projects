package Program;
import java.util.Locale;
import java.util.Scanner;
import java.util.function.BiFunction;


public class testmain 
{	

	static void writeVinyl(vinyl t)
	{
		c("--------------------------------------------------------------");
		c("| Type: " + t.getType());
		c("| Name: " + t.getName());
		if(!t.getSurname().equals(""))
			c("| Surname: " + t.getSurname());
        c("| Title: " + t.getTitle());
        c("| Edition: " + t.getEdition());
        c("| Distributor: " + t.getDist());
        c("| Price: " + t.getPrice());
        c("| RPM: " + t.getRPM());
        c("| Date: " + t.getDay() + "." + t.getMonth() + "." + t.getYear());
        c("--------------------------------------------------------------");
	}
	
	static void c(String message) 
	{
	    System.out.println(message);
	}
	
    public static void main(String[] args) 
    {
    	
    	String wybor=""; 
    	String type, nam="", edt="", dist="", sur="", ttl="", oldnam="", oldsur="", pass, zn;
    	double pr=-999999, rpm, min, max, percent, oldpr;
    	int i, j, y=0, m=0, d=0, sep;
    	Scanner scanner = new Scanner(System.in);
        storage collection = new storage();
        
        i=collection.readPass();
        if(i==1)
        {
        	c("Set a password for modifications: ");
        	pass=scanner.nextLine();
        	collection.setPassword(pass);
        	collection.savePass();
        }
        c("Which decimal separator do you use? \n1. Comma (,)  \n2. Dot (.)");
        sep=scanner.nextInt();
        if(sep==1)
        	scanner.useLocale(Locale.FRANCE);
        if(sep==2)
        	scanner.useLocale(Locale.US);
         do
        {
        	c("MENU:");
            c("a. Add new");
            c("b. List all");
            c("c. Clear all");
            c("d. Save to file");
            c("e. Read from file");
            c("f. Browse through the records");
            c("g. Search");
            c("h. Browse through the found records");
            c("i. Sort");
            c("j. Search and change");
            c("k. Trashbin");
            c("q. Quit");
            wybor=scanner.nextLine();
           
            switch(wybor)
            {
            case "a":
            	do
            	{
	            	c("Type: ");
	            	c("Vinyl - click 'v'");
	            	wybor = scanner.nextLine();
	            	switch(wybor)
	            	{
	            		case "v":
	            			j = collection.quantity;
	            			collection.addNewVinyl("", "", 0, 0, 0, 0, "", "", "", 33, "");
		            		type="Vinyl"; 
		            		collection.getVinyl(j).setType(type);
		            		c("Name: ");
			            	nam = scanner.nextLine();
			            	collection.getVinyl(j).setName(nam);
			                c("Surname (if not needed, press enter): ");
			                sur = scanner.nextLine();	
			                collection.getVinyl(j).setSurname(sur);
			                c("Title: ");
			                ttl = scanner.nextLine();
			                collection.getVinyl(j).setTitle(ttl);
			                do {
				                c("RPM: ");
				                rpm = scanner.nextDouble();
				                scanner.nextLine();	
				                i =  collection.getVinyl(j).setRPM(rpm);
				                if(i==1)
				                	c("Wrong value. Try again.");
			                }while(i==1);
			                c("Edition: ");
			                edt = scanner.nextLine();
			                collection.getVinyl(j).setEdition(edt);
			                c("Distributor: ");
			                dist = scanner.nextLine(); 
			                collection.getVinyl(j).setDist(dist);
			                do {
				                c("Price: ");
				                pr = scanner.nextDouble();
				                i = collection.getVinyl(j).setPrice(pr);
				                if(i==1)
				                	c("Wrong choice. Try again.");
			                }while(i!=0);
			                do
			                {
				                c("Date (dd-mm-yyyy):");
				                c("Day: ");
				                d = scanner.nextInt();
				                c("Month: ");
				                m = scanner.nextInt();                    
				                c("Year: ");
				                y =  scanner.nextInt();
				                i = collection.getVinyl(j).setDate(y,m,d);
				                if (i == 1) 
				                {
				                    c("Incorrect year. Try again.");
				                } 
				                 if (i == 2) 
				                {
				                    c("Incorrect month. Try again.");
				                } 
				                else if (i == 3) 
				                {
				                    c("Incorrect day (1-31). Try again.");
				                } 
				                else if (i == 4) 
				                {
				                    c("Incorrect day (1-29). Try again.");
				                } 
				                else if (i == 5) 
				                {
				                    c("Incorrect day (1-28). Try again.");
				                } 
				                else if (i == 6) 
				                {
				                    c("Incorrect day (1-30). Try again.");
				                } 
				             }while (i != 0);
			                c("Added! Click ENTER to proceed.");
			                break;
                
				             default: 
				            	 c("Wrong choice. Try again.");
				            	 continue;
		            	}
		            	break;
	            	}while(true);
            		scanner.nextLine();
	            	break;
            
            case "b":
            	if(collection.quantity == 0)
            		c("No discs. Try adding new or reading from file");
            	else
            	{
	            	for (i = 0; i < collection.quantity; i++) 
	                {
	                	 writeVinyl(collection.getVinyl(i));
	                }
            	}
            	c("Press any key to continue.");
            	scanner.nextLine();
            	break;
            
            case "c":
            	c("Password: ");
				pass=scanner.nextLine();
				if(!pass.equals(collection.getPassword()))
				{
					c("Wrong password.");
					break;
				}
            	c("Are you sure you want to clear everything?\n y - yes      n - no");
            	wybor=scanner.nextLine();
            	switch(wybor)
            	{
            		case "y":
            			collection.clearVinyls();
            			c("Opened. Click any key to proceed.");
            			scanner.nextLine();
            			break;
            		case "n":
            			break;
            		default:
            			c("Unknown choice. Try again.");
            			break;
            	}
            	break;
                                  
            case "d":
            	c("Password: ");
				pass=scanner.nextLine();
				if(!pass.equals(collection.getPassword()))
				{
					c("Wrong password.");
					break;
				}
            	c("Are you sure you want to upwrite the file? \n y - yes      n - no");
            	wybor=scanner.nextLine();
            	switch(wybor)
            	{
            		case "y":
            			collection.saveToFile();
            			c("Saved. Click any key to proceed.");
            			scanner.nextLine();
            			break;
            		case "n":
            			break;
            		default:
            			c("Unknown choice. Try again.");
            			break;
            	}
            	break;
            case "e":
            	c("Are you sure you want to lose your work and open the file? \n y - yes      n - no");
            	wybor=scanner.nextLine();
            	switch(wybor)
            	{
            		case "y":
            			collection.readFromFile();
            			i=collection.readFromFileTrash();
            			if(i==1)
            				c("File 'trash' does not exist.");
            			c("Opened. Click any key to proceed.");
            			scanner.nextLine();
            			break;
            		case "n":
            			break;
            		default:
            			c("Unknown choice. Try again.");
            	}
            	break;
            case "f":
            	i=collection.getCurrent();
				if (i==-1)
				{
					c("No elements. Click any key to proceed.");
					scanner.nextLine();
				}
				else
				{
					do
					{
						if (collection.getCurrent()==-1)
						{
							c("No elements. Click ENTER to proceed.");
							scanner.nextLine();
							break;
						}
						writeVinyl(collection.getVinyl(i));
						c("    a - previous   b - next   c - change index    d - delete    m - menu");
						wybor = scanner.nextLine();
						switch(wybor)
						{
							case "a":
								collection.previous();
								i=collection.getCurrent();
								break;
							case "b":
								collection.next();
								i=collection.getCurrent();
								break;	
							case "c":
								c("Password: ");
    							pass=scanner.nextLine();
    							if(!pass.equals(collection.getPassword()))
    							{
    								c("Wrong password.");
    								break;
    							}
								c("Do you want to change the whole index or one of the categories?");
								c("1 - all  2 - name 3 - surname 4 - title  5 - edition  6 - distributor  7 - price  8 - RPM  9 - date  0 - leave");
								wybor = scanner.nextLine();
								switch(wybor)
								{
									case "1":
										do
						            	{
							            	c("Type: ");
							            	c("Vinyl - click 'v'");
							            	wybor = scanner.nextLine();
							            	switch(wybor)
							            	{
							            		case "v":
								            		type="Vinyl"; 
								            		c("Name: ");
									            	nam = scanner.nextLine();
									            	collection.getTab().setName(nam);
									                c("Surname (if not needed, type 'n'): ");
									                sur = scanner.nextLine();
									                collection.getTab().setSurname(sur);			               			                
									                c("Title: ");
									                ttl = scanner.nextLine();	
									                collection.getTab().setTitle(ttl);
									                do 
									                {
										                c("RPM: ");
										                rpm = scanner.nextInt();
										                i = collection.getTab().setRPM(rpm);
										                if(i==1)
										                	c("Zła wartość");
									                }while(i==1);
									                scanner.nextLine();	
									                c("Edition: ");
									                edt = scanner.nextLine();
									                collection.getTab().setEdition(edt);
									                c("Distributor: ");
									                dist = scanner.nextLine(); 
									                collection.getTab().setDist(dist);
									                do 
									                {
										                c("Price: ");
										                pr = scanner.nextDouble();
										                i = collection.getTab().setPrice(pr);
										                if(i==1)
										                	c("Wrong choice. Try again.");
									                }while(i!=0);
									                do
									                {
										                c("Date (dd-mm-yyyy):");
										                c("Day: ");
										                d = scanner.nextInt();
										                c("Month: ");
										                m = scanner.nextInt();                    
										                c("Year: ");
										                y =  scanner.nextInt();
										                i = collection.getTab().setDate(y,m,d);
										                if (i == 1) 
										                {
										                    c("Incorrect year. Try again.");
										                } 
										                 if (i == 2) 
										                {
										                    c("Incorrect month. Try again.");
										                } 
										                else if (i == 3) 
										                {
										                    c("Incorrect day (1-31). Try again.");
										                } 
										                else if (i == 4) 
										                {
										                    c("Incorrect day (1-29). Try again.");
										                } 
										                else if (i == 5) 
										                {
										                    c("Incorrect day (1-28). Try again.");
										                } 
										                else if (i == 6) 
										                {
										                    c("Incorrect day (1-30). Try again.");
										                } 
										             }while (i != 0);
									                c("Changed! Click any key to proceed.");
									                break;
						                
										             default: 
										            	 c("Unknown choice. Try again.");
										            	 continue;
								            	}
								            	break;
							            	}while(true);
						            		scanner.nextLine();
							            	break;
										
									case "2":
										c("Name: ");
										nam=scanner.nextLine();
										collection.getTab().setName(nam);
										c("Changed! Press any key to continue");
										scanner.nextLine();
										break;
									case "3":
										c("Surname: ");
										sur=scanner.nextLine();
										collection.getTab().setSurname(sur);
										c("Changed! Press any key to continue");
										scanner.nextLine();
										break;
									case "4":
										c("Title: ");
										ttl=scanner.nextLine();
										collection.getTab().setTitle(ttl);
										c("Changed! Press any key to continue");
										scanner.nextLine();
										break;
									case "5":
										c("Edition: ");
										edt=scanner.nextLine();
										collection.getTab().setEdition(edt);
										c("Changed! Press any key to continue");
										scanner.nextLine();
										break;
									case "6":
										c("Distributor: ");
										dist=scanner.nextLine();
										collection.getTab().setDist(dist);
										c("Changed! Press any key to continue");
										scanner.nextLine();
										break;
									case "7":
										c("Price: ");
										pr=scanner.nextDouble();
										collection.getTab().setPrice(pr);
										c("Changed! Press any key to continue");
										scanner.nextLine();
										break;
									case "8":
										c("RPM: ");
										rpm=scanner.nextDouble();
										collection.getTab().setRPM(rpm);
										c("Changed! Press any key to continue");
										scanner.nextLine();
										break;
									case "9":
										do
						                {
							                c("Date (dd-mm-yyyy):");
							                c("Day: ");
							                d = scanner.nextInt();
							                c("Month: ");
							                m = scanner.nextInt();                    
							                c("Year: ");
							                y =  scanner.nextInt();
							                i=collection.getTab().setDate(y,m,d);
							                if (i == 1) 
							                {
							                    c("Incorrect year. Try again.");
							                } 
							                 if (i == 2) 
							                {
							                    c("Incorrect month. Try again.");
							                } 
							                else if (i == 3) 
							                {
							                    c("Incorrect day (1-31). Try again.");
							                } 
							                else if (i == 4) 
							                {
							                    c("Incorrect day (1-29). Try again.");
							                } 
							                else if (i == 5) 
							                {
							                    c("Incorrect day (1-28). Try again.");
							                } 
							                else if (i == 6) 
							                {
							                    c("Incorrect day (1-30). Try again.");
							                } 
							             }while (i != 0);
						                 c("Added! Click ENTER to proceed.");
						                 break;
						            case "0":
						            	break;
						            	
						            default:
						                c("Unknown choice. Try again.");
								}
								break;
							case "d":
								c("Password: ");
    							pass=scanner.nextLine();
    							if(!pass.equals(collection.getPassword()))
    							{
    								c("Wrong password.");
    								break;
    							}
								c("Are you sure you want to delete current index?");
								c("y - yes           n - no");
								wybor = scanner.nextLine();
								switch(wybor)
								{
									case "y":
										i=collection.getCurrent();
										collection.deleteCurrentVinyl(i);
										c("Deleted. Click any key to continue.");
										i=collection.getCurrent();
										scanner.nextLine();
										break;
									case "n":
										break;
									default:
						                c("Unknown choice. Try again.");
								}
								break;
							case "m":
								break;
							default:
				                c("Unknown choice. Try again.");
						}
					}while(!wybor.equals("m"));
				}
				break;
            
            case "g":
            	c("What do you want to search for?");
				c("1 - Search for an artist");
				c("2 - Search for a surname");
				c("3 - Search for price range");
				c("4 - Search for RPM");
				c("5 - Search for titles starting with...");
				c("l - leave");
				wybor=scanner.nextLine();
				switch(wybor)
				{
					case "1":
						c("Name: ");
						nam=scanner.nextLine();
						c("Surname (if not needed, click enter): ");
						sur=scanner.nextLine();
						i = collection.searchArtist(nam, sur);
						if(i==0)
						{
							c("Nothing was found.");
						}
						else
						{
							c("Found. Click ENTER to proceed.");
						}
						scanner.nextLine();
						break;
					case "2":
						c("Surname: ");
						sur=scanner.nextLine();
						i=collection.searchSurname(sur);
						if(i==0)
						{
							c("Nothing was found. Click ENTER to proceed");
						}
						else
						{
							c("Found. Click ENTER to proceed.");
						}
						scanner.nextLine();
						break;
					case "3":
						c("Min: ");
						min=scanner.nextDouble();
						c("Max: ");
						max=scanner.nextDouble();;
						i=collection.searchPrice(min,max);
						if(i==1)
							c("Found. Click ENTER to proceed.");
						else if(i==2)
							c("Minimum too low! Click ENTER to proceed and try again.");
						else if(i==3)
							c("Maximum too high! Click ENTER to proceed and try again.");
						else if(i==4)
							c("Maximum is lower than minimum! Click ENTER to proceed and try again.");
						else
							c("Nothing found. Click ENTER to proceed.");
						scanner.nextLine();
						break;
					case "4":
						c("RPM: ");
						rpm=scanner.nextDouble();
						i=collection.searchRPM(rpm);
						if(i==0)
							c("Nothing was found. Click ENTER to proceed");
						else
							c("Found. Click ENTER to proceed.");
						scanner.nextLine();
						break;
					case "5":
						c("Starting with...: ");
						zn=scanner.nextLine();
						i=collection.searchTitleLength(zn);
						if(i==0)
							c("Nothing was found. Click ENTER to proceed");
						else
							c("Found. Click ENTER to proceed.");
						scanner.nextLine();
						break;
					case "l":
						break;
				}
				break;
            	
            case "h":
            	i=collection.getCurrentFound();
				if (i==-1)
				{
					c("No elements. Click ENTER to proceed.");
					scanner.nextLine();
				}
				else
				{
					do
					{
						if(collection.getCurrentFound()==-1)
						{
							c("No elements. Click ENTER to leave.");
							scanner.nextLine();
							break;
						}
						writeVinyl(collection.getVinylFound(i));
						c("    a - previous     b - next       d - delete index      t - delete all indexes    m - menu");
						wybor=scanner.nextLine();
						switch(wybor)
						{
							case "a":
								collection.previousFound();
								i=collection.getCurrentFound();
								break;
							case "b":
								collection.nextFound();
								i=collection.getCurrentFound();
								break;	
							case "d":
								c("Password: ");
    							pass=scanner.nextLine();
    							if(!pass.equals(collection.getPassword()))
    							{
    								c("Wrong password.");
    								break;
    							}
								c("Are you sure you want to delete current index?");
								c("y - yes           n - no");
								wybor=scanner.nextLine();
								switch(wybor)
								{
									case "y":
										collection.deleteCurrentFound();
										c("Deleted. Click ENTER to continue.");
										i=collection.getCurrentFound();
										scanner.nextLine();
										break;
									case "n":
										break;
								}
								break;
							case "t":
								c("Password: ");
    							pass=scanner.nextLine();
    							if(!pass.equals(collection.getPassword()))
    							{
    								c("Wrong password.");
    								break;
    							}
								c("Are you sure you want to delete all found data?");
								c("y - yes           n - no");
								wybor=scanner.nextLine();
								switch(wybor)
								{
									case "y":
										
										collection.deleteAllFound();
										c("Deleted. Click ENTER to proceed.");
										scanner.nextLine();
										break;
									case "n":
										break;
								}
							case "m":
								break;
						}
					}while(!wybor.equals("m"));
				}
				break;
            
            case "i":
            	c("By which category you want to sort?");
            	c("1 - Sort by artist \n2 - Sort by price \n3 - Sort by date \nl - leave");
            	wybor = scanner.nextLine();
            	switch(wybor)
            	{
            		case "1": 
            			collection.sortArtist();
            			c("Sorted. Click any key to proceed");
            			scanner.nextLine();
            			break;
            		case "2":
            			collection.sortPrice();
            			c("Sorted. Click any key to proceed");
            			scanner.nextLine();
            			break;
            		case "3":
            			collection.sortDate();
            			c("Sorted. Click any key to proceed");
            			scanner.nextLine();
            			break;
            		case "l":
            			break;
            		default:
                        c("Unknown choice. Try again.");
            	}
            	break;
            case "j":
            	c("Password: ");
				pass=scanner.nextLine();
				if(!pass.equals(collection.getPassword()))
				{
					c("Wrong password.");
					break;
				}
            	c("What do you want to change?");
                c("1 - Artist");
                c("2 - Price by percent (price range)");
                c("3 - Price by percent (exact price)");
                c("4 - Price by number (price range)");
                c("5 - Price by number (exact price)");
                wybor = scanner.nextLine();

                switch (wybor) {
                    case "1":
                        c("Enter old artist: ");
                        c("Name: ");
                        oldnam = scanner.nextLine();
                        c("Surname (if needed): ");
                        oldsur = scanner.nextLine();
                        c("Enter new artist: ");
                        c("Name: ");
                        nam = scanner.nextLine();
                        c("Surname (if needed): ");
                        sur = scanner.nextLine();
                        i = collection.changeArtist(oldnam, oldsur, nam, sur);
                        if(i==0)
                        	c("Changed. Press ENTER to proceed.");
                        if(i==1)
                        	c("Not found. Press ENTER to proceed.");
                        scanner.nextLine();
                        break;

                    case "2":
                        c("Enter price range:");
                        c("Minimum: ");
                        min = scanner.nextDouble();
                        c("Maximum: ");
                        max = scanner.nextDouble();
                        c("Enter percent ('-' will be treated as a discount): ");
                        percent = scanner.nextDouble();

                        i = collection.changePricePercent(percent, min, max);

                        if (i == 1) 
                            c("Minimum too low! Press ENTER to proceed and try again.");
                        else if (i == 2) 
                            c("Maximum too high! Press ENTER to proceed and try again.");
                        else if (i == 3) 
                            c("Maximum is lower than minimum! Press ENTER to proceed and try again.");
                        else if (i == 4) 
                            c("Percent too small. Can't be below -100. Press ENTER to proceed and try again.");
                        else if (i == 5) 
                            c("Percent too high. Can't be above 200. Press ENTER to proceed and try again.");
                        else if (i == 6) 
                            c("None found. Press ENTER to proceed.");
                        else 
                            c("Changed. Press ENTER to proceed.");
                        scanner.nextLine();
                        break;

                    case "3":
                        c("Enter the price you seek for:");
                        oldpr = scanner.nextDouble();
                        c("Enter percent ('-' will be treated as a discount): ");
                        percent = scanner.nextDouble();

                        i = collection.changePricePercentExact(percent, oldpr);

                        if (i == 1) 
                            c("Changed. Press ENTER to proceed.");
                        else 
                            c("None found. Press ENTER to proceed.");
                        scanner.nextLine();
                        break;

                    case "4":
                        c("Enter price range you seek for:");
                        c("Minimum: ");
                        min = scanner.nextDouble();
                        c("Maximum: ");
                        max = scanner.nextDouble();
                        c("Enter new price: ");
                        pr = scanner.nextDouble();

                        i = collection.changePriceNumber(pr, min, max);

                        if (i == 1) 
                            c("Minimum too low! Press ENTER to proceed and try again.");
                        else if (i == 2) 
                            c("Maximum too high! Press ENTER to proceed and try again.");
                        else if (i == 3) 
                            c("Maximum is lower than minimum! Press ENTER to proceed and try again.");
                        else if (i == 4) 
                            c("Price can't be below 0. Press ENTER to proceed and try again.");
                        else if (i == 5) 
                            c("Price can't be more than 2000000. Press ENTER to proceed and try again.");
                        else if (i == 6) 
                            c("None found. Press ENTER to proceed.");
                        else 
                            c("Changed. Press ENTER to proceed.");
                        scanner.nextLine();
                        break;

                    case "5":
                        c("Enter the price you seek for:");
                        oldpr = scanner.nextDouble();
                        c("Enter new price: ");
                        pr = scanner.nextDouble();

                        i = collection.changePriceNumberExact(pr, oldpr);

                        if (i == 1) 
                            c("Changed. Press ENTER to proceed.");
                        else 
                            c("None found. Press ENTER to proceed.");
                        scanner.nextLine();
                        break;

                    default:
                        c("Invalid option. Please enter a number from 1 to 5.");
                        break;
                }
                break;
            
            case "k":
            	i=collection.getCurrentTrash();
    			if (i==-1)
    			{
    				c("No elements. Click ENTER to proceed.");
    				scanner.nextLine();
    			}
    			else
    			{
    				do
    				{
    					if(collection.getCurrentTrash()==-1)
    					{
    						c("No elements. Click ENTER to leave.");
    						scanner.nextLine();
    						break;
    					}
    					writeVinyl(collection.getVinylTrash(i));
    					c("    a - previous          b - next        d - delete index      t - delete all indexes   j - add back   q - leave)");
    					wybor = scanner.nextLine();
    					switch(wybor)
    					{
    						case "a":
    							collection.previousTrash();
    							i=collection.getCurrentTrash();
    							break;
    						case "b":
    							collection.nextTrash();
    							i=collection.getCurrentTrash();
    							break;	
    						case "d":
    							c("Password: ");
    							pass=scanner.nextLine();
    							if(!pass.equals(collection.getPassword()))
    							{
    								c("Wrong password.");
    								break;
    							}
    							c("Are you sure you want to delete current index?");
    							c("y - yes           n - no");
    							wybor = scanner.nextLine();
    							switch(wybor)
    							{
    								case "y":
    									collection.deleteCurrentTrash();
    									c("Deleted. Click ENTER to proceed.");
    									i=collection.getCurrentTrash();
    									scanner.nextLine();
    									break;
    								case "n":
    									break;
    								default:
    									c("Unknown choice. Try again.");
    									break;
    							}
    							break;
    						case "t":
    							c("Password: ");
    							pass=scanner.nextLine();
    							if(!pass.equals(collection.getPassword()))
    							{
    								c("Wrong password.");
    								break;
    							}
    							c("Are you sure you want to delete all found data?");
    							c("y - yes           n - no");
    							wybor = scanner.nextLine();
    							switch(wybor)
    							{
    								case "y":	
    									collection.deleteAllTrash();
    									c("Deleted. Click ENTER to proceed.");
    									scanner.nextLine();
    									break;
    								case "n":
    									break;
    								default:
    									c("Unknown choice. Try again.");
    									break;
    							}
    							break;
    						case "j":
    							c("Password: ");
    							pass=scanner.nextLine();
    							if(!pass.equals(collection.getPassword()))
    							{
    								c("Wrong password.");
    								break;
    							}
    							collection.addBackTrash();
    							c("Added back. Click ENTER to proceed.");
    							scanner.nextLine();
    							break;
    						case "q":
    							break;
    						default:
    							c("Unknown choice. Try again.");
    							break;
    					}
    				}while(!wybor.equals("q"));
    			}
    			break;	
            
            case "q":
            	c("Do you want to save your trashbin?");
            	c("y - yes			n - no");
            	wybor = scanner.nextLine();
				switch(wybor)
				{
					case "y":
						collection.saveToFileTrash();
						c("Saved");
						break;
					case "n":
						break;
					default:
		                c("Unknown choice. Try again.");
				}
            	c("Are you sure you want to leave? (Remember to save your work!).");
				c("n - NO			l - leave");
				wybor = scanner.nextLine();
				switch(wybor)
				{
					case "l":
						c("Period.");
						scanner.nextLine();
						break;
					case "n":
						break;
					default:
		                c("Unknown choice. Try again.");
				}
				break;
            
            default:
                c("Unknown choice. Try again.");
            
            }
        	
        	
        }while(!wybor.equals("l"));
        scanner.close();
        System.exit(-1);
        
     } 
    
}
 

