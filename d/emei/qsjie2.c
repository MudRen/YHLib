inherit ROOM;

void create()
{
      set("short", "��ʯ��");
      set("long", @LONG
�Ѿ��Ƕ���ɽ�����ˡ�����һ��ͨ�����ҵ���ʯ�ף�����
������Σ�����ʮ�����¡����Ϸ�ͨ����گ�Ĵ���������ߺ�
�����˴��˸�С���
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "northeast" : __DIR__"qsjie1",
          "southwest" : "/d/dali/road1",
          "southup"   : __DIR__"bgsgate",
          "west"      : __DIR__"caopeng",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
