inherit ROOM;

void create()
{
       set("short","ܽ�ض���");
       set("long",@LONG
ֻ���˴���һ��С����������С��ֻ����һ��ͨ��������
ȴ���һ�����⡣
LONG);
       set("exits",([
              "enter":__DIR__"furong1",
       ]));
	
       setup();
       replace_program(ROOM);
}
