inherit ROOM;

void create()
{
        set("short", "ǰԺ");
        set("long", @LONG
һ���۳ɻ�ɫ��ΧǽȦ�����Ժ�ӣ�һ����ʯ��ͨ����
������������������µĴ��ţ�����һ����¥�ǹ�¥����
������¥��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"xianguosi",
  		"north" : __DIR__"tianwang",
  		"east" : __DIR__"gulou",
  		"west" : __DIR__"zhonglou",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
