package controller.model;

import java.io.StringReader;
import java.io.StringWriter;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.w3c.dom.CharacterData;


public class xmlManager {

    //********************************reader**********************************************

    public String[] xmlReader(String xml){
        String data[]=new String[2];

        try {

            DocumentBuilder db = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            InputSource is = new InputSource();
            is.setCharacterStream(new StringReader(xml));

                Document doc = db.parse(is);
            NodeList nodes = doc.getElementsByTagName("user");

            for (int i = 0; i < nodes.getLength(); i++) {
                Element element = (Element) nodes.item(i);

                NodeList name = element.getElementsByTagName("name");
                Element line = (Element) name.item(0);
                data[0]= getCharacterDataFromElement(line);

                NodeList title = element.getElementsByTagName("username");
                line = (Element) title.item(0);
                data[1]= getCharacterDataFromElement(line);
            }

            return data;
        }catch (Exception e){
            e.printStackTrace();
            return null;
        }

    }

    public static String getCharacterDataFromElement(Element e) {
        Node child = e.getFirstChild();
        if (child instanceof CharacterData) {
            CharacterData cd = (CharacterData) child;
            return cd.getData();
        }
        return "";
    }

    //******************************writer***************************

    public String xmlWritter(int Op,User user,Song song) {

        //Document Builders

        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dbuilder;

        try {

            dbuilder=dbFactory.newDocumentBuilder();
            Document doc=dbuilder.newDocument();

            //Create a root element

            Element rootElement=doc.createElementNS("","root");
            doc.appendChild(rootElement);

            //Append child to root element

            //set operation number
            Element op=doc.createElement("op");
            op.appendChild(doc.createTextNode(Integer.toString(Op)));
            rootElement.appendChild(op);

            //set data

            Element data=doc.createElement("data");
            rootElement.appendChild(data);

            if(user!=null){

                data.appendChild(setUser(doc,user));
                //data.appendChild(setSong(doc,song));

            }else{

                data.appendChild(setSong(doc,song));

            }

            //Set String Format to XML

            TransformerFactory transformerFactory=TransformerFactory.newInstance();
            Transformer transformer=transformerFactory.newTransformer();
            //transformer.setOutputProperty(OutputKeys.INDENT,"yes");
            DOMSource source=new DOMSource(doc);

            StringWriter writer=new StringWriter();

            StreamResult string=new StreamResult(writer);

            transformer.transform(source,string);

            System.out.print(writer.toString());
            return writer.toString();


        } catch (Exception e) {
            e.printStackTrace();
            return null;

        }
    }


    private static Node setUser(Document doc,User user){

        Element User = doc.createElement("user");



        //append name node
        User.appendChild(nodeElements(doc,User,"name",user.getFullName()));

        //append username node
        User.appendChild(nodeElements(doc,User,"username",user.getUserName()));

        //append password node
        User.appendChild(nodeElements(doc,User,"password",user.getPassword()));

        //append age node
        User.appendChild(nodeElements(doc,User,"age",Integer.toString(user.getAge())));

        //append email node
        User.appendChild(nodeElements(doc,User,"email",user.getEmail()));


        return User;
    }


    private static  Node setSong(Document doc,Song song){

        Element Song=doc.createElement("song");

        //append name
        Song.appendChild(nodeElements(doc,Song,"name",song.getSongName()));

        //append artist
        Song.appendChild(nodeElements(doc,Song,"artist",song.getSongArtist()));

        //append album
        Song.appendChild(nodeElements(doc,Song,"album",song.getSongAlbum()));

        //append rating
        Song.appendChild(nodeElements(doc,Song,"rating",Integer.toString(song.getSongRating())));

        //append genre
        Song.appendChild(nodeElements(doc,Song,"genre",song.getSongGenre()));

        //append votes
        Song.appendChild(nodeElements(doc,Song,"votes",Integer.toString(song.getVotes())));

        //append sum
        Song.appendChild(nodeElements(doc,Song,"sum",Integer.toString(song.getSum())));

        //append lyrics
        Song.appendChild(nodeElements(doc,Song,"lyrics",song.getSongLyrics()));

        //append file64
        Song.appendChild(nodeElements(doc,Song,"file64",song.getSongfile64()));

        return Song;

    }


    //utility method to create text node
    private static Node nodeElements(Document doc, Element element, String name, String value) {

        Element node = doc.createElement(name);
        node.appendChild(doc.createTextNode(value));

        return node;
    }

}
