
inherit PRIVATE_ROOM;

void create()
{
	set("short", "���θ�");
	set ("long", @LONG
��������һ�ǵ����θ�������紵��Ҷ�������������ķǳ���
�У����������Ŀ�������ʵ����һ�������书�ĺ�ȥ���� 
LONG );

	set("exits", ([
                "west" : __DIR__"zhulin",
	]));

        set("sleep_room", 1);
        setup();

        set("research_improve", 15);  //15% improved
    
        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
