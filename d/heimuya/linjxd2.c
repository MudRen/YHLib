inherit ROOM;

void create()
{
  	set("short", "�ּ�С��");
  	set("long", @LONG
������һ����Ϊ�������ּ�С���ϣ���������ɭɭ������
�֡�һ����紵�����ң�����ɳɳ�����������㲻����������
�����ߺ�����һ��ɽ�ȡ� 
LONG);
        set("outdoors", "heimuya");
  	set("exits", ([
      		"south" : __DIR__"fenggate1",
      		"north" : __DIR__"linjxd4",
  	]));
  	set("no_clean_up", 0);
  	setup();
  	replace_program(ROOM);
}
