inherit ROOM;

void create ()
{
  set ("short", "���᷿");
  set ("long", @LONG
��������ά��Ĵ��������Ӣ��ס�������ҵļҽ̼��ϣ�����Ӣÿ������
Ҫ�����������п�ʱ��Ҫ���顣��������û�и��ҵ��ݻ���ǽ�Ϲ���һ����
���ͼ����ֻ������Ϸ����������飬�����ʶ�ֻ���಼�ġ�
LONG);

  	set("exits", ([
  		"north" : __DIR__"stone_road4",
	]));

  	set("objects", ([
                 CLASS_D("zhenyuan") + "/wangjianying" : 1,
        ]));

  	setup();
        replace_program(ROOM);
}