inherit ROOM;

void create()
{
	set("short","�軨԰����");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����
վ�ڲ軨԰���ſڣ�������԰��ɫ��������ϲ���������߾�
��԰�ˣ�������һ��ʯ������
LONG);
	set("outdoors", "dali");
	set("exits", ([
	    "east" : __DIR__"chahua7",
	    "west" : __DIR__"yongdao2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

