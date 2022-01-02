import  QtQuick 1.0
import  LuxDomoVarLight  1.0
import   "../content"
Rectangle
{
     id:varLightEdit
     objectName: "acEdit"
     width: 700
     height: 480
     color: "#00000000"

     property string   volume: ""
     property string   arrowsCondition: ""
     property int        pointX: 300
     function  init(type,deviceUid){  pLuxDomoVarLightItem.init(type,deviceUid)  }

     LuxDomoVarLightItem
     {
         id:pLuxDomoVarLightItem
         objectName: "pLuxDomoVarLightItem"
     }

     MouseArea
     {
         anchors.fill: parent
     }

     Item
     {
         width: parent.width/2
         height: parent.height*5/9
         anchors.verticalCenter: parent.verticalCenter
         x:pointX
         Image
         {
             anchors.fill: parent
             source: "../home_manage/deviceEdit_top.png"
         }
         Column
         {
             anchors.fill: parent
             Item
             {
                 width: parent.width
                 height: parent.height/5
                 Rectangle
                 {
                    width: parent.width*9/10
                    height: 1
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "#bfbfbf"
                 }
                 LuxDomoLabel
                 {
                      anchors.fill: parent
                      textName: "可控灯设置"
                      textSize: 27
                      textColor: "#141512"
                 }
             }
             Item
             {
                 width: parent.width
                 height: parent.height/5
                 Row
                 {
                     width: parent.width
                     height: parent.height*4/5
                     anchors.left: parent.left
                     anchors.bottom: parent.bottom
                     Item
                     {
                           width: parent.width*2/5
                           height: parent.height
                           LuxDomoLabel
                           {
                                 anchors.fill: parent
                                 textName: "亮度选择"
                                 textColor: "#676767"
                                 textSize: 20
                           }
                     }
                     Item
                     {
                         width: parent.width*3/5
                         height: parent.height
                         Image
                         {
                             width: parent.width*2/3
                             height: parent.height
                             source:arrowsCondition=="volume"?"../home_manage/option_on.png":"../home_manage/option_off.png"
                         }
                         LuxDomoStyleLabel
                         {
                             width: parent.width*2/3
                             height: parent.height
                             anchors.left: parent.left
                             anchors.top: parent.top
                             textName: varLightEdit.volume
                             textSize: 22
                             textColor: "#151412"
                             textImage:arrowsCondition=="volume"?"../home_manage/up_arrows.png":"../home_manage/down_arrows.png"
                             onClicked:
                             {
                                 arrowsCondition="volume"
                                 pLuxDomoVarLightItem.showVolumeList()
                             }
                         }
                     }
                 }
             }
             Item
             {
                 width: parent.width
                 height: parent.height/5
             }
             Item
             {
                 width: parent.width
                 height: parent.height*2/5
                 Row
                 {
                     width: parent.width
                     height: parent.height/2
                     anchors.verticalCenter: parent.verticalCenter
                     anchors.horizontalCenter: parent.horizontalCenter
                     Item
                     {
                          width: parent.width/2
                          height: parent.height
                          LuxDomoButton
                          {
                                 height: parent.height
                                 width: parent.width/2
                                 anchors.verticalCenter: parent.verticalCenter
                                 anchors.horizontalCenter: parent.horizontalCenter
                                 name:"取消"
                                 fontsize:22
                                 textcolor: "#24c3be"
                                 onClicked: {  pLuxDomoVarLightItem.close()  }
                          }
                     }
                     Item
                     {
                         width: parent.width/2
                         height: parent.height
                         LuxDomoButton
                         {
                                height: parent.height
                                width: parent.width/2
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                                name:"确定"
                                fontsize:22
                                textcolor: "#24c3be"
                                onClicked: {  pLuxDomoVarLightItem.save()   }
                         }
                     }
                 }
             }
         }
     }
}
