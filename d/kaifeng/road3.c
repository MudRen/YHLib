inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������ϱ��Ĵ�ֵ���Ҳ�ǻʵ۳�Ѳʱ��Ҫ������
�ߵĵ���¥�󲻶ϣ�ʵ���˼�һ����̧����ȥ��������۵ķ�
����Ȼ��������ͷ��������һ���󸮵ڱ����������첨�︮��
LONG);
        set("objects", ([
  		__DIR__"npc/fujiazi" : 1,
	]));
        set("outdoors", "kaifeng");
        set("exits", ([
  		"east" : __DIR__"ciqi",
  		"west" : __DIR__"yangfu",
  		"south" : __DIR__"road2",
  		"northup" : __DIR__"road4",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
