inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��СС����ı����̣����������ı����ɴ�Ѱ
���������Ȼ�����ѵ�һ�������õ��˸���ϡ�١��ƹ������
�����ֱ��ë����ת���Ϳ���ǽ�ϵ����ơ�
LONG );
	set("objects", ([
		__DIR__"npc/tanghuai" : 1,
	]));
	set("exits", ([
	    	"southeast" : __DIR__"northroad1",
	]));

	setup();
	replace_program(ROOM);
}

