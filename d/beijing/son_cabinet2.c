inherit ROOM;

void create ()
{
  set ("short", "���᷿");
  set ("long", @LONG
��������ά��Ķ����������ܵ�ס�������ҵļҽ̼��ϣ�������ÿ������
Ҫ�����������п�ʱ��Ҫ���顣��������û�и��ҵ��ݻ���ǽ�Ϲ���һ����
���ͼ����ֻ������Ϸ����������飬�����ʶ�ֻ���಼�ġ�
LONG);

  	set("exits", ([
  		"south" : __DIR__"stone_road4",
	]));

  	setup();
        replace_program(ROOM);
}