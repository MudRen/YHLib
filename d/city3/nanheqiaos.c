inherit ROOM;

void create()
{
	set("short","�Ϻ���");
	set("long",@LONG
�����ǳɶ��������Ϻ��š����Ӻ��ϺӼг���������Ϊ��
Ȼ�Ļ��Ǻӣ�����������츮֮���Ĵ����׸����򱱽��ǣ���
������һ��С·��
LONG);
	set("outdoors", "chengdu");
	set("exits", ([
                "south"  : "/d/xuedao/sroad1",
                "north"  : __DIR__"southgate",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

