inherit ROOM;

void create()
{
      set("short", "��ʮ�ŵ���");
      set("long", @LONG
���������ġ���ʮ�ŵ��ա�����·��������ǧ�۰ٻء���
˵��ȥ���и�������ķ�ɮ���ˣ���һ������·��������������
�����ǵ�֪�˴��о�����û�󣬱���Ҳ���˸�������Ĳ�ľ��
�ԡ����ӡ���֮���ɴ˶�����ǧ���֣�������϶���
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "southwest" : __DIR__"jsjdg3",
          "eastdown"  : __DIR__"jsjdg1",
      ]));
      setup();
      replace_program(ROOM);
}
