inherit ROOM; 
 
void create ()
{
  set ("short", "����");
  set ("long", @LONG
���ӵ��м���һ�Ŵ����ӣ��������������ʮ���ˡ����ӵ�һ��ͨ��������
��һ�߿���ȥ�������ھ���Ŀ��˶�ʱ���������ﶼ�����£��ɴ���ǰԺ�յ�
��¶�����硣
LONG);

  	set("exits", ([
  		"east" : __DIR__"kitchen_road1",
  		"west" : __DIR__"zhengting",
  		"north" : __DIR__"e_garden",
	]));

	setup(); 
	replace_program(ROOM); 
} 
