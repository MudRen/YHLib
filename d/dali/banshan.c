inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
һ��Ƭï�ܵĳ������������ڰ�ɽ���Ļ����ϡ����Ӷ�
���������������˵�ǣ�������Ҫ�Ľ������ϣ�Ҳ���ճ���
����Ʒ��ԭ���ϡ�ɽ�µĴ�ׯ��İ����˾�����ɽ���ɷ���
�ӡ�����ɽ����Ϫ���£�������ˮ���Ѿ��Ĵ�ɽ�񾭳���
�����µ����Ӷ���Ϫ�У�����˳ˮƮ���������Ӹ�����Ϫˮ
������������
LONG);
	set("objects", ([
	   	__DIR__"npc/kanzhuren": 2,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"northup"  : __DIR__"shanjian",
	    	"east"     : __DIR__"buxiongbu",
	]));
	setup();
	replace_program(ROOM);
}

