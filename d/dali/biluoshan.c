inherit ROOM;

void create()
{
	set("short","����ɽ��");
	set("long",@LONG
�˼���������ɽ���£�����������ɽ�¶��ϣ����ؿ���
һ��Ҳ�����֣������ϡ�衣���ĵ���ũҵ������л���
�ָ��������ڲ�ͬ�ļ��ڸ�����ͬ����أ���฽��������
�����������˸�����
LONG);
	set("objects", ([
	   	__DIR__"npc/nongfu": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"west"      : __DIR__"yixibu",
	]));
	setup();
	replace_program(ROOM);
}

