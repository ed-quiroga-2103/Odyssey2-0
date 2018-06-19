package controller.model;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class User {

    //*******************************Class fields******************************//

    //User data
    private String image64;
    private final StringProperty userName;
    private final StringProperty fullName;
    private final StringProperty password;
    private final IntegerProperty age;
    private final StringProperty email;


    //*******************************Class Methods******************************//


    //Constructor class (Overload)

   public User(){

       this.userName=new SimpleStringProperty("");
       this.fullName=new SimpleStringProperty("");
       this.age=new SimpleIntegerProperty(0);
       this.password=new SimpleStringProperty("");
       this.email=new SimpleStringProperty("");

   }

    public User(String userName,String fullName,int age,String password,String email){

        this.userName=new SimpleStringProperty(userName);
        this.fullName=new SimpleStringProperty(fullName);
        this.age=new SimpleIntegerProperty(age);
        this.password=new SimpleStringProperty(password);
        this.email=new SimpleStringProperty(email);

    }

    //Setters and Getters

    public String getUserName() {
        return userName.get();
    }

    public StringProperty userNameProperty() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName.set(userName);
    }

    public String getFullName() {
        return fullName.get();
    }

    public StringProperty fullNameProperty() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName.set(fullName);
    }

    public int getAge() {
        return age.get();
    }

    public IntegerProperty ageProperty() {
        return age;
    }

    public void setAge(int age) {
        this.age.set(age);
    }

    public String getPassword() {
        return password.get();
    }

    public StringProperty passwordProperty() {
        return password;
    }

    public void setPassword(String password) {
        this.password.set(password);
    }

    public String getEmail() {
        return email.get();
    }

    public StringProperty emailProperty() {
        return email;
    }

    public void setEmail(String email) {
        this.email.set(email);
    }

    public String getImage64() {
        return image64;
    }

    public void setImage64(String image64) {
        this.image64 = image64;
    }
}
