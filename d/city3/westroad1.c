inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ڳɶ�����������ϣ�����һ���������Ĵ�·��
����һֱ���졣·�����������������ò����֡�С��С������
������ЩС�����������ɼ��������Ÿ�ͷ��������䡣����
��ȴ�Ե��ر��徲����������ġ����Ϸ���ͨ���ϴ�֡�
LONG);
        set("outdoors", "chengdu");
	set("exits", ([
	    	"southwest"  : __DIR__"qingyanggong",
	    	"southeast"  : __DIR__"southroad3",
	    	"north"      : __DIR__"westroad2",
	]));
	set("objects", ([
	    	"/d/village/npc/seller": 1,
	    	"/d/city/npc/liumang"  : 1,
	]));
	setup();
	replace_program(ROOM);
}
