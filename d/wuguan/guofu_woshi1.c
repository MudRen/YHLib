inherit ROOM;

void create()
{
    	set("short","��Ϣ��");
    	set("long", @LONG
�����ǹ����ڵ���Ϣ�ң������е��ɣ����Ǵ�ɨ�ķǳ�
�ɾ���һ�Ŵ��̿�ǽ���ţ������ȥҲ��һ����Ϣ�ң����ϵ�
���˽�����Ϣ���Ѻ���ȥ�������ĵ��Ҹ�����˯��������
LONG);
        set("exits", ([
            	"east" : __DIR__"guofu_woshi2",
            	"south" : __DIR__"guofu_lang6",
        ]));
        set("no_fight", 1);
        set("sleep_room", 1);
        setup();
}
