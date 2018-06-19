package controller.view;

import controller.model.PlayList;
import controller.model.Song;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import controller.MainApp;
import javafx.scene.image.ImageView;
import javafx.scene.media.AudioClip;
import javafx.stage.FileChooser;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.util.Base64;


import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;

public class DisplayController {

    private PlayList currentPlayList;
    private MainApp mainApp;
    private ObservableList<Song> playSongList = FXCollections.observableArrayList();

    @FXML
    private Label name;
    @FXML
    private Label creator;
    @FXML
    private Label year;
    @FXML
    private TableView<Song> songTableView;
    @FXML
    private TableColumn<Song,String> songColumn;
    @FXML
    private ImageView image;


    public DisplayController(){}

    @FXML
    private void initialize(){

        songColumn.setCellValueFactory(cellData -> cellData.getValue().songNameProperty());

        songTableView.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) ->showSongData());


    }

    public void setPlayList(PlayList playList){
        this.currentPlayList=playList;
        this.setPlayListData();
        this.setPlayListSongs();
        this.songTableView.setItems(this.playSongList);

    }

    public void setMainApp(MainApp mainApp){
        this.mainApp=mainApp;
    }

    private void setPlayListData(){

        this.name.setText(currentPlayList.getName());
        this.creator.setText(currentPlayList.getCreator());
        this.year.setText(Integer.toString(currentPlayList.getYear()));

    }

    private void setPlayListSongs(){
        this.playSongList.clear();
        Song current=currentPlayList.getRoot();

        while(current!=null){

            this.playSongList.add(current);
            current=current.getNext();
        }
    }

    private void updatePhoto(){

        byte[] bytes=mainApp.converter.decode64(currentPlayList.getImage64());
        this.image.setImage(new javafx.scene.image.Image(new ByteArrayInputStream(bytes)));
    }

    private void showSongData(){
        this.mainApp.initSongData(songTableView.getSelectionModel().getSelectedItem());
    }

    @FXML
    private void getBack(){
        this.mainApp.initMainContent();
    }

    @FXML
    private void rateSong(){
        this.mainApp.initRatingPanel();
    }

    @FXML
    private void loadImage(){
        FileChooser chooser=new FileChooser();
        FileChooser.ExtensionFilter extFilters=new FileChooser.ExtensionFilter("png files(*.png)","*.png");
        chooser.getExtensionFilters().add(extFilters);

        File file = chooser.showOpenDialog(mainApp.getPrimaryStage());
        currentPlayList.setImage64(mainApp.converter.encode64(file));
        this.updatePhoto();
    }

    @FXML
    private void addSong(){
        Song tempSong=new Song();
        mainApp.initAddSongPanel(tempSong);
        this.currentPlayList.add(tempSong);
        this.setPlayListSongs();
    }

    @FXML
    private void playSong(){
        System.out.print("te la creiste wei");
    }


}
