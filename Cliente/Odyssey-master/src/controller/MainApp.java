package controller;

import java.io.*;

import controller.model.*;
import controller.view.*;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.image.Image;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.scene.image.ImageView;
import org.jdom.input.SAXBuilder;
import java.io.StringReader;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamWriter;



public class MainApp extends Application {

    //*******************************Class fields******************************//

    private Stage primaryStage;
    private BorderPane borderPane;
    private User currentUser;
    public Base64Converter converter=new Base64Converter();
    public Client client = new Client("127.0.0.1", 8081); //Socket
    private ObservableList<User> friendList = FXCollections.observableArrayList();
    private ObservableList<PlayList> songList= FXCollections.observableArrayList();
    private ObservableList<Notification> notificationList= FXCollections.observableArrayList();
    public xmlManager xmlManager=new xmlManager();

    //*******************************Class Methods******************************//

    @Override
    public void start(Stage primaryStage){

        this.primaryStage=primaryStage;
        this.primaryStage.setTitle("Odyssey++ 2.0");

        initBorderPane(); //set the border pane
        initSignIn();  //set the welcome page
    }


    public MainApp(){

        //testing Data

        Song test=new Song("Llegaste tu","test","Juan Luis Guerra feat.Luis Fonsi","test","Bachata");
        PlayList temp=new PlayList("My PlayList","Gunther Karolyi",2018);
        temp.add(test);
        this.songList.add(temp);
        this.songList.add(new PlayList("My PlayList2","Gunther Karolyi",2018));
        this.friendList.add(new User("karolyi15","Gunther Karolyi",20,"","karolyi15@hotmail.com"));
        this.friendList.add(new User("quiroga_1","Eduardo Quiroga",5,"","soyunrico@hotmail.com"));

    }

    public Stage getPrimaryStage() {


        return primaryStage;
    }

    public void setCurrentUser(User user){
        this.currentUser=user;
    }

    public User getCurrentUser(){
        return this.currentUser;
    }

    public ObservableList<User> getFriendList(){
        return friendList;
    }
    public ObservableList<PlayList> getSongList(){
        return songList;
    }
    public ObservableList<Notification> getNotificationList(){
        return notificationList;
    }

    public void initBorderPane(){

        try{

            //load fxml
            FXMLLoader loader=new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey BordePane.fxml"));
            borderPane =(BorderPane) loader.load();

            //set to stage as a scene
            Scene scene=new Scene(borderPane);
            primaryStage.setScene(scene);
            primaryStage.show();

        }catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void initSignIn(){
        try{

            //load fxml Wrapper
            FXMLLoader loader=new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey SignIn.fxml"));
            AnchorPane odysseySignIn= (AnchorPane) loader.load();


            //set ad image
            Image OdyddeyAd=new Image("ad.jpg");
            ImageView logo= new ImageView();
            logo.setImage(OdyddeyAd);


            //set to border pane
            borderPane.setCenter(odysseySignIn);
            borderPane.setLeft(logo);

            //set controller
            SignInController controller = loader.getController();
            controller.setMainApp(this);

        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public void initSignUp(){

        try {

            //load fxml Wrapper
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey SignUp.fxml"));
            AnchorPane odysseySignUp = (AnchorPane) loader.load();


            //set to border pane
            borderPane.setCenter(odysseySignUp);


            //set controller
            SignUpController controller = loader.getController();
            controller.setMainApp(this);


        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public void initContent() {

        try {

            //load fxml content
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey2.0 Content.fxml"));
            borderPane= (BorderPane) loader.load();


            //set to border pane
            Scene scene=new Scene(borderPane);
            primaryStage.setScene(scene);
            this.initMainContent();



            //set controller
            Controller controller = loader.getController();
            controller.setMainApp(this);



        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void initMainContent(){
        try {

            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey2.0 contentMain.fxml"));
            AnchorPane odysseyMainContent = (AnchorPane) loader.load();

            borderPane.setCenter(odysseyMainContent);

            mainContentController controller=loader.getController();
            controller.setMainApp(this);


        }catch (IOException e){
            e.printStackTrace();
        }

    }

    public void initDisplayContent(PlayList playList){
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey2.0 contentDisplay.fxml"));
            AnchorPane odysseyMainContent = (AnchorPane) loader.load();

            borderPane.setCenter(odysseyMainContent);

            DisplayController controller=loader.getController();
            controller.setMainApp(this);
            controller.setPlayList(playList);
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public void initUserData(){
        try {

            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey2.0 UserData.fxml"));
            AnchorPane odysseyUserData = (AnchorPane) loader.load();

            borderPane.setCenter(odysseyUserData);

            UserDataController controller=loader.getController();
            controller.setMainApp(this);
            controller.setUser();

        }catch (IOException e){
            e.printStackTrace();
        }

    }

    public void initSongData(Song song){
        try{
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey2.0 SongData.fxml"));
            AnchorPane page = (AnchorPane) loader.load();

            borderPane.setCenter(page);

            SongDataController controller=loader.getController();
            controller.setMainApp(this);
            controller.setCurrentSong(song);




        }catch (IOException e){
            e.printStackTrace();
        }

    }

    public void initFriendData(User user){
        try{
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey2.0 FriendData.fxml"));
            AnchorPane page = (AnchorPane) loader.load();

            Stage dialogStage=new Stage();
            dialogStage.setTitle("Friend Data");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            dialogStage.initOwner(primaryStage);
            Scene scene=new Scene(page);
            dialogStage.setScene(scene);

            //set controller
            FriendDataController controller=loader.getController();
            controller.setMainApp(this);
            controller.setUser(user);

            dialogStage.showAndWait();

        }catch (IOException e){
            e.printStackTrace();
        }
    }
    public void showErrorDialog(String content){

        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Error Dialog");
        alert.setHeaderText(null);
        alert.setContentText(content);

        alert.showAndWait();

    }

    public void showInfoDialog(String content){

        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Information Dialog");
        alert.setHeaderText(null);
        alert.setContentText(content);

        alert.showAndWait();
    }

    public void initNotificationPanel(){

        try{

            //init loader
            FXMLLoader loader=new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey NotificationsPanel.fxml"));
            AnchorPane page=(AnchorPane) loader.load();

            borderPane.setCenter(page);




        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public void initAddSongPanel(Song song){
        try{

            //init loader
            FXMLLoader loader=new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey AddSong.fxml"));
            AnchorPane page=(AnchorPane) loader.load();

            //set stage for scene
            Stage dialogStage=new Stage();
            dialogStage.setTitle("Song Panel");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            dialogStage.initOwner(primaryStage);
            Scene scene=new Scene(page);
            dialogStage.setScene(scene);

            //set controller
            AddSongController controller=loader.getController();
            controller.setDialogStage(dialogStage);
            controller.setSong(song);

            //show window
            dialogStage.showAndWait();


        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public void initRatingPanel(){
        try {

            //init loader
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(MainApp.class.getResource("view/Odyssey RatingPanel.fxml"));
            AnchorPane page = (AnchorPane) loader.load();

            //set stage for scene
            Stage dialogStage=new Stage();
            dialogStage.setTitle("Rating Panel");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            dialogStage.initOwner(primaryStage);
            Scene scene =new Scene(page);
            dialogStage.setScene(scene);

            //set controller
            //RatingPanelController controller=loader.getController();
            //controller.setDialogStage(dialogStage);
            //controller.setSong(song);

            //show window
            dialogStage.showAndWait();


        }catch (IOException e){
            e.printStackTrace();
        }

    }

    /*public JSONObject sendRequest(int opnum,String content){
        try {
            //built wrapper

            Wrapper wrapper = new Wrapper();
            wrapper.setCData(content);
            wrapper.setOpnum(opnum);

            //convert to xml format and send to server
            //server is going to return a String with a xml

            return unmarshalXml(client.sendData(marshalXml(wrapper)));

        }catch (Exception e){
            this.showErrorDialog("Error in server connection!");
            return null;
        }
    }*/

    public String marshalXml(Wrapper wrapper){

        try {

            ByteArrayOutputStream out = new ByteArrayOutputStream();
            XMLStreamWriter writer = XMLOutputFactory.newInstance().createXMLStreamWriter(out);

            //Writing the xml
            writer.writeStartElement("oddata");
            writer.writeStartElement("data");
            writer.writeStartElement("opnum");
            writer.writeCharacters(String.valueOf(wrapper.getOpnum()));
            writer.writeEndElement();
            writer.writeStartElement("CData");
            writer.writeCharacters(wrapper.getCData());
            writer.writeEndElement();
            writer.writeEndElement();
            writer.writeEndElement();
            writer.close();

            //Return xml in String format
            return out.toString();



        }catch (XMLStreamException e)
        {
            e.printStackTrace();
            return null;
        }

    }

    /*public JSONObject unmarshalXml(String xml){

        org.jdom.input.SAXBuilder saxBuilder = new SAXBuilder();
        try {

            //Read xml in String format

            org.jdom.Document doc1 = saxBuilder.build(new StringReader(xml));

            //Return json object with data of server

            return jsonParser(doc1.getRootElement().getChild("data").getChild("CData").getText());

        }catch (IOException e){
            e.printStackTrace();
            return null;
        }catch (org.jdom.JDOMException e){
            e.printStackTrace();
            return null;
        }
    }*/


    public static void main(String[] args) {
        launch(args);
    }
}
