inherit ROOM;

void create()
{
      set("short", "��ʮ����");
      set("long", @LONG
��ʮ���̣���·���ն��ͣ��ػ����ۣ����˲��ܴ�Ϣ��·
���Ǳ����������ɼ�֣�·��������׵ľ���Ͽ�ȡ��ɴ���
������������µ�ϴ��ء�
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "northdown" : __DIR__"leidongping",
          "southwest" : __DIR__"bashisipan2",
          "southeast" : __DIR__"lengsl2",
      ]));
      setup();
      replace_program(ROOM);
}
