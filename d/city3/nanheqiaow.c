inherit ROOM;

void create()
{
	set("short","�Ϻ���");
	set("long",@LONG
�����ǳɶ��������Ϻ��š����Ӻ��ϺӼг��������ǻ���
����츮֮�����׸�֮�ء���ˮ���±�͸�������������ţ���
������佻�Ϫ�ˡ�
LONG);
	set("outdoors", "chengdu");
	set("exits", ([
            	"west" : __DIR__"path1",
            	"east" : __DIR__"westgate",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

