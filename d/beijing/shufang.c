inherit ROOM;

void create ()
{
  set ("short", "�鷿");
  set ("long", @LONG
̤����������һ�۾Ϳ���ǽ�ϵ�һ�����ƾ��ᣬ����ʮ�ĸ����֣�������
��ʷ˭�������������ʤ���ˡ������ܵ�����ϰ����˸�ʽ�������鼮������
ս�������Ӱټң���һ���С������������һ�ܴ���ʯ���磬ת��ȥֻ������
������ССľ齣�������ȥ����������Ⱥ�����ޡ�
LONG);

  	set("exits", ([
  		"out" : __DIR__"cabinet2",
	]));

  	set("objects", ([
                CLASS_D("zhenyuan") + "/wangweiyang" : 1,
       ]));

  	setup();
        replace_program(ROOM);
}
