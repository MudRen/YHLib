inherit ROOM;

void create ()
{
	set ("short", "ɽ·");
  	set ("long", @LONG
����һ�����������ɽ·����Ϊ����ɽ�ȼ���ɽ�����Ƚ�
Զ�����������ǿ�����·�������˺ܶ࣬·�������Զ���и�
Сͤ�ӹ�����Ъ�ţ�����ȥ��Զ���ǿ���ǡ��ɱ�����ֱͨ��
ɽ���ɴ�ǰס��ɽ���㡢����Ŀ������ﲻ����
LONG);

  	set("outdoors", "kaifeng");
  	set("exits", ([
  		"eastdown" : __DIR__"jiaowai",
  		"westdown" : __DIR__"shanlu2",
	]));

  	setup();
        replace_program(ROOM);
}
