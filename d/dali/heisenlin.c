inherit ROOM;

void create()
{
	set("short", "��ɭ��");
	set("long", @LONG
ӭ��һ��Ƭ��ѹѹ��ɭ�֣��ߴ�Ĺ��ɲ������������һ
�ž������������������Щ�ر𡣱���һ������·ͨ��������
�ڣ��ϱ߲�Զ���������ĵ���ˡ�
LONG);
	set("outdoors", "kunming");
	set("exits", ([
                "south" : __DIR__"dasenlin",
                "northeast" : "/d/kunming/htroad3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

