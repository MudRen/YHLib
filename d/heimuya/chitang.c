inherit ROOM;

void create()
{
  	set("short","����");
  	set("long", @LONG
�������������ú��һ��С������������������ԧ������
��䣬�ر߻�����ֻ�׺�����ʳ��
LONG);

  	set("exits",([
      		"north" : __DIR__"tian1",
      		"west"  : __DIR__"shenggu",
      		"east"  :__DIR__"chufang2",
  	]));
  	setup();
  	replace_program(ROOM);
}
