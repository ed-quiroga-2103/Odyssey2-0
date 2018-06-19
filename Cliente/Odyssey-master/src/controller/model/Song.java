package controller.model;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class Song {

    //*******************************Class fields******************************//


    private final StringProperty songName;
    private final StringProperty songAlbum;
    private final StringProperty songArtist;
    private final StringProperty songLyrics;
    private final StringProperty songGenre;
    private final IntegerProperty songRating;
    private Song next;
    private String image64;
    private String songfile64;
    private int votes=0;
    private int sum =0;

    
    //*******************************Class Methods******************************//


    //Constructor class (Overload)

    public Song(){

        this.songName=new SimpleStringProperty("");
        this.songAlbum=new SimpleStringProperty("");
        this.songArtist=new SimpleStringProperty("");
        this.songLyrics=new SimpleStringProperty("");
        this.songGenre=new SimpleStringProperty("");
        this.songRating=new SimpleIntegerProperty(0);
    }

    public Song(String songName,String songAlbum,String songArtist,String songLyrics,String songGenre){

        this.songName=new SimpleStringProperty(songName);
        this.songAlbum=new SimpleStringProperty(songAlbum);
        this.songArtist=new SimpleStringProperty(songArtist);
        this.songLyrics=new SimpleStringProperty(songLyrics);
        this.songGenre=new SimpleStringProperty(songGenre);
        this.songRating=new SimpleIntegerProperty(0);
    }


    //Setters and Getters

    public String getSongName() {
        return songName.get();
    }

    public StringProperty songNameProperty() {
        return songName;
    }

    public void setSongName(String songName) {
        this.songName.set(songName);
    }

    public String getSongAlbum() {
        return songAlbum.get();
    }

    public StringProperty songAlbumProperty() {
        return songAlbum;
    }

    public void setSongAlbum(String songAlbum) {
        this.songAlbum.set(songAlbum);
    }

    public String getSongArtist() {
        return songArtist.get();
    }

    public StringProperty songArtistProperty() {
        return songArtist;
    }

    public void setSongArtist(String songArtist) {
        this.songArtist.set(songArtist);
    }

    public String getSongLyrics() {
        return songLyrics.get();
    }

    public StringProperty songLyricsProperty() {
        return songLyrics;
    }

    public void setSongLyrics(String songLyrics) {
        this.songLyrics.set(songLyrics);
    }

    public String getSongGenre() {
        return songGenre.get();
    }

    public StringProperty songGenreProperty() {
        return songGenre;
    }

    public void setSongGenre(String songGenre) {
        this.songGenre.set(songGenre);
    }

    public Song getNext() {
        return next;
    }

    public void setNext(Song next) {
        if(next!=null) {
            this.next = next;
        }else{
            this.next=null;
        }
    }

    public String getImage64() {
        return image64;
    }

    public void setImage64(String image64) {
        this.image64 = image64;
    }

    public String getSongfile64() {
        return songfile64;
    }

    public void setSongfile64(String songfile64) {
        this.songfile64 = songfile64;
    }

    public int getVotes() {
        return votes;
    }

    public void setVotes(int votes) {
        this.votes = votes;
    }

    public int getSum() {
        return sum;
    }

    public void setSum(int sum) {
        this.sum = sum;
    }

    public int getSongRating() {
        return songRating.get();
    }

    public IntegerProperty songRatingProperty() {
        return songRating;
    }

    public void setSongRating(int songRating) {
        this.songRating.set(songRating);
    }
}
