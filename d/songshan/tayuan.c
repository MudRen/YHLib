
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����±�ɽ���ϣ��Ƿ�������Ժ��Ժ����ʮ������ܷ�����
�߽���ʮ�ɣ�����������Ժ��������������Ĺ����������������
LONG );
	set("exits", ([
		"southdown" : __DIR__"fawangsi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

