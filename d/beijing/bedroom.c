inherit ROOM; 
 
void create ()
{
  	set ("short", "�ͷ�");
  	set ("long", @LONG
�ھ�����˰����ǵ������д����ܵ��ޱȣ��ѷ��䲼�õķǳ����ʡ���ľ
��������һ���ò裬���ż��̵��ġ��ݽ���¯�ﴫ��һ�������㡣һ�ſ����
��Ĵ������ű��죬���˲��������˯��
LONG);

  	set("exits", ([
  		"east" : __DIR__"front_yard2",
	]));

        set("no_fight", 1);
        set("no_steal", 1);
        set("sleep_room", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
} 
