inherit ROOM;

void create()
{
      set("short", "��ɼ��");
      set("long", @LONG
����Ƭ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ����
��һ�飬֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿
��Ҳ�ޡ������Ϻ��Ŀ�֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG);
      set("exits", ([
          "east"      : __DIR__"bashisipan1",
          "northdown" : __DIR__"lengsl1",
          "southwest" : __DIR__"lengsl3",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
