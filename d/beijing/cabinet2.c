// Room: /d/zhenyuan/cabinet2.c
// created by agah 

inherit ROOM;

void create ()
{
  	set ("short", "������¥");
  	set ("long", @LONG
����Է���Ϊ���ʣ�����һ����̴ľ�󰸣��ķ��ı��뱸������һ��СС
�辰�����ⰻȻ��ת�����磬ӭ��ֻ��һ��д��ɽˮ�������ݺᡣ�Ա߾�����
齣�����ˮ��ɴ�ʣ�����Щ����
LONG);

  	set("exits", ([
  		"enter" : __DIR__"shufang",
  		"down" : __DIR__"cabinet",
	]));
  	setup();
        replace_program(ROOM);
}
