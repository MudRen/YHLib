inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
��������˵�ǡ����ߴ����еİ�������������֮��������
�ľ���죬����е���������ͦ���Σ�֦Ҷ����������������
ӵ�𣬴�Ϊ��ʱһ��ɮ����������������һ��ֲ��һ�꣬��ֲ
�����ǧ�߰���ʮ���꣬ʱ�ƹŵ��֡����ﱱ���������֣���
����������
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "east"      : __DIR__"qingyinge",
          "west"      : __DIR__"gudelin2",
          "northup"   : __DIR__"wannianan",
          "southeast" : __DIR__"gudelin1",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
