package controller.view;

import controller.model.Notification;
import controller.model.PlayList;
import controller.model.Song;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import controller.MainApp;
import controller.model.User;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import java.io.IOException;
import java.io.StringWriter;
import java.util.Optional;

public class Controller {


    //*******************************Class fields******************************//

    //set table views and columns

    @FXML
    private TableView<PlayList> songTableView;
    @FXML
    private TableColumn<PlayList,String> songColumn;

    @FXML
    private TableView<User> friendTableView;
    @FXML
    private TableColumn<User,String> friendColumn;

    private MainApp mainApp;

    //*******************************Class Methods******************************//



    public Controller(){
    }

    @FXML
    private void initialize(){

        //set column data

        songColumn.setCellValueFactory(cellData -> cellData.getValue().nameProperty());
        friendColumn.setCellValueFactory(cellData -> cellData.getValue().userNameProperty());


        //get selected Wrapper in Labels while click an option

        songTableView.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) ->showPlayList(songTableView.getSelectionModel().getSelectedItem()));
        friendTableView.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) ->FriendDataPanel(friendTableView.getSelectionModel().getSelectedItem()));

    }

    public void setMainApp(MainApp mainApp){

        this.mainApp=mainApp;

        //set table views data

        songTableView.setItems(mainApp.getSongList());
        friendTableView.setItems(mainApp.getFriendList());

    }

    private void showPlayList(PlayList playList){
        this.mainApp.initDisplayContent(playList);
    }

    @FXML
    private void UserDataPanel(){
        this.mainApp.initUserData();
    }


    private void FriendDataPanel(User user){
        this.mainApp.initFriendData(user);
    }


    /*@FXML
    private void openNotification(){
        int selectedIndex=notificationTableView.getSelectionModel().getSelectedIndex();
        if(selectedIndex>=0) {
            Notification selectedNotification = notificationTableView.getSelectionModel().getSelectedItem();
            mainApp.initNotificationPanel(selectedNotification);
            notificationTableView.getItems().remove(selectedIndex);
        }else{
            mainApp.showErrorDialog("Please select a Notification!");
        }
    }*/

    @FXML
    private void AddNewSong(){
        Song tempSong=new Song();
        mainApp.initAddSongPanel(tempSong);

    }

    /*@FXML
    private void editSong(){
        int selectedIndex=songTableView.getSelectionModel().getSelectedIndex();
        if(selectedIndex>=0) {
            Song selectedSong = songTableView.getSelectionModel().getSelectedItem();

            JSONObject tempJson=new JSONObject();
            tempJson.put("song",selectedSong.getSongName());

            mainApp.initAddSongPanel(selectedSong);

            tempJson.put("newName",selectedSong.getSongName());
            tempJson.put("artist",selectedSong.getSongArtist());
            tempJson.put("lyrics",selectedSong.getSongLyrics());
            tempJson.put("album",selectedSong.getSongAlbum());

            JSONObject jsonAnswer=mainApp.sendRequest(4,this.newJson(tempJson));
            if(jsonAnswer.get("confirmation").equals(true)){
                showSongData(selectedSong);
                JSONArray array=(JSONArray)jsonAnswer.get("songs");
                this.mainApp.updateSongList(array);
                this.mainApp.showInfoDialog("You edited a song");
            }else{
                showSongData(null);
                this.mainApp.showErrorDialog("Error in editing song!!");
            }



        }else{
            mainApp.showErrorDialog("Please select a song");
        }

    }

    @FXML
    private void deleteSong(){
        int selectedIndex=songTableView.getSelectionModel().getSelectedIndex();
        if(selectedIndex>=0) {

            JSONObject tempJson=new JSONObject();
            tempJson.put("song",mainApp.getSongList().get(selectedIndex).getSongName());

            JSONObject jsonAnswer=mainApp.sendRequest(3,this.newJson(tempJson));
            if(jsonAnswer.get("confirmation").equals(true)){

                JSONArray array=(JSONArray)jsonAnswer.get("songs");
                mainApp.updateSongList(array);
                mainApp.showInfoDialog("You deleted a song!!");

            }else{
                mainApp.showErrorDialog("Error in deleting song!!");
            }

        }else{
            mainApp.showErrorDialog("Please select a song");
        }
    }

    @FXML
    private void sendNotification(){
        int selectedIndex=friendTableView.getSelectionModel().getSelectedIndex();
        if(selectedIndex>=0) {
            if (currentSong != null) {
                Notification notification = new Notification(mainUser.getFullName(), currentSong.getSongName());

                JSONObject tempJson=new JSONObject();
                tempJson.put("friend",mainApp.getFriendList().get(selectedIndex).getUserName());
                tempJson.put("song",this.currentSong.getSongName());
                tempJson.put("user",this.mainUser.getFullName());

                JSONObject jsonAnswer=mainApp.sendRequest(10,this.newJson(tempJson));
                if(jsonAnswer.get("confirmation").equals(true)){
                    mainApp.showInfoDialog("Successful, you sent a notification to your friend!");

                }else{
                    mainApp.showErrorDialog("Error in sending notification!!");
                }




            } else {
                mainApp.showInfoDialog("You are not playing a song");
            }
        }else{
            mainApp.showErrorDialog("Please select a friend");
        }
    }

    @FXML
    private void rateSong(){

        Song selectedSong=songTableView.getSelectionModel().getSelectedItem();
        if(selectedSong!=null){
            mainApp.initRatingPanel(selectedSong);
        }else{
            mainApp.showErrorDialog("Please select a song!!");
        }
    }*/

    @FXML
    private void close(){
        System.exit(0);
    }

    @FXML
    private void info(){
        mainApp.showInfoDialog("Version 2.0\n2018");
    }


    @FXML
    private void logOut(){
        mainApp.initBorderPane();
        mainApp.initSignIn();
    }


    /*@FXML
    private void addFriend(){
        TextInputDialog dialog = new TextInputDialog("");
        dialog.setTitle("Add new friend");
        dialog.setHeaderText(null);
        dialog.setContentText("Please enter your friend username:");

        // Traditional way to get the response value.
        Optional<String> result = dialog.showAndWait();
        if (result.isPresent()){
            JSONObject tempJson=new JSONObject();
            tempJson.put("friend",result.get());
            JSONObject jsonAnwer=mainApp.sendRequest(9,newJson(tempJson));
            if(jsonAnwer.get("confirmation").equals(true)){
                JSONArray array=(JSONArray) jsonAnwer.get("friends");
                mainApp.updateFriendList(array);
                mainApp.showInfoDialog("New friend added!!");
            }else{
                mainApp.showErrorDialog("Error in adding friend");
            }
        }else{
            mainApp.showErrorDialog("Please enter a friend username");
        }
    }*/
}
