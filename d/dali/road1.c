inherit ROOM;
void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��������᫵�ɽ����·��������ԭͨ�����Ĺٵ���
�˴������ϣ�������ȥ����ɽ·ͨ���ƹ�ɽ�����̶��ɴ�����
���������ȥ�򱱲�Զ����������������ɽ����ȥ��Զ���Ե�
������������
LONG);
	set("outdoors", "dali");
	set("exits", ([
	    "northeast"  : "/d/emei/qsjie2",
	    "southwest"  : __DIR__"road2",
	    "east"  : "/d/kunming/xroad2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

