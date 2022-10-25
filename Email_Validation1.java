///Write a program to Email Validation using regex in java

import java.util.regex.*;    
import java.util.*;    
public class EmailValidation2{  
    public static void main(String args[]){  
        ArrayList<String> emails = new ArrayList<String>();  
        emails.add("javaTpoint@domain.co.in");  
        emails.add("javaTpoint@domain.com");  
        emails.add("javaT-point#@domain.co.in");  
        emails.add("javaT_point@domain.com");  
        emails.add("javaTpoint@domaincom");  
        //Add invalid emails in list  
        emails.add("@yahoo.com");  
        emails.add("12javaTpoint#domain.com");  
        //Regular Expression   
        String regex = "^[A-Za-z0-9+_.-]+@(.+)$";  
        //Compile regular expression to get the pattern  
        Pattern pattern = Pattern.compile(regex);  
        //Iterate emails array list  
        for(String email : emails){  
            //Create instance of matcher   
            Matcher matcher = pattern.matcher(email);  
            System.out.println(email +" : "+ matcher.matches()+"\n");  
        }  
    }  
}  
Outpu
