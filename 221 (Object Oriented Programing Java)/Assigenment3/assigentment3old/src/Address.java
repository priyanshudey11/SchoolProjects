public class Address 
{
    // Stores the street name
    private String street; 
    // Stores the city name
    private String city; 
    // Stores the state name
    private String state; 
    // Stores the zip code
    private String zipcode; 

    public Address(String street, String city, String state, String zipcode) 
    {
        // Initialize the street variable with the provided value
        this.street = street; 
        // Initialize the city variable with the provided value
        this.city = city; 
        // Initialize the state variable with the provided value
        this.state = state; 
        // Initialize the zipcode variable with the provided value
        this.zipcode = zipcode; 
    }

    public String getStreet() 
    {
         // Returns the street name
        return street;
    }

    public String getCity() 
    {
        // Returns the city name
        return city; 
    }

    public String getState() 
    {
        // Returns the state name
        return state; 
    }

    public String getZipcode() 
    {
        // Returns the zip code
        return zipcode; 
    }

    public String toString()
    {
        // Returns a formatted string representation of the address, including the street, city, state, and zipcode
        return "    " + street + "\n    " + city + ", " + state + " " + zipcode;
        
    }
}
