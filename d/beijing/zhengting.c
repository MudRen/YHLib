inherit ROOM; 
 
void create ()
{
  	set ("short", "����");
  	set ("long", @LONG
���ſڹ���һ����ң����顸�����˷���ĸ����֣�����������ò����硣
������ʦվ�����ԡ�����ͷ�Ķ����������������ڵ��е�̫ʦ���ϣ���������
ͷ��ά��������ͣ����������ھ���������������������������������ͷ
Ц��Ц��Ҳ������Ϊû����˵�������ϵ����պ����ࡣ
LONG);

  	set("exits", ([
  		"east" : __DIR__"dining_room",
  		"west" : __DIR__"pianting",
  		"south" : __DIR__"front_yard2",
  		"north" : __DIR__"c_garden",
	]));

  	set("objects", ([
               CLASS_D("zhenyuan") + "/wangjianjie" : 1,
        ]));

	setup();
        "/clone/board/zhenyuan_b"->foo();
} 

int valid_leave(object me, string dir)
{
        object wang;

        if (dir != "north" &&
            dir != "east" &&
            dir != "west" ||
            ! objectp(wang = present("wang jianjie", this_object())))
                return ::valid_leave(me, dir);

        return wang->permit_pass(me, dir);
}
