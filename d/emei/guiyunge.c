inherit ROOM;

void create()
{
      set("short", "���Ƹ�");
      set("long", @LONG
���Ƹ�ԭ���ƴ����������ʦ�ĵ������δ��������ɮ
��ʿ���������ؽ������Ƹ�������Ů�壬���Ͽɵִ������
���ǹ����á�
LONG);
      set("objects", ([
           __DIR__"npc/boydizi" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits", ([
          "eastdown"  : __DIR__"guanyintang",
          "westup"    : __DIR__"chunyangdian",
          "southup"   : __DIR__"yunufeng",
      ]));
      set("outdoors", "emei");
      setup();
      replace_program(ROOM);
}
