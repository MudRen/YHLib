inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
������һ�����ݳ��������ľ�¥������¥���Ե��Ϊ��ɫ
ש��ľ��ʯ���߽�¥�ڣ�һ�۱��ܿ���һ����������ͼ
�����˱��軭��Ω��ΩФ��¥������ϱ��������ſ���������
Ʒ�裬ֻ����С��æ�Ĳ����ֺ���
LONG);
	set("outdoors", "suzhou");
	set("exits", ([
		"west" : __DIR__"beidajie2",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2": 1,
	]));
	setup();
	replace_program(ROOM);
}

