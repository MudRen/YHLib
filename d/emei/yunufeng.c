inherit ROOM;

void create()
{
      set("short", "��Ů��");
      set("long", @LONG
���ǹ��Ƹ�ߵ���Ů�壬�嶥��һ���ĳ߼�����С�أ���
���ĳߣ��ļ����ݣ���Ϊ��Ů��ԡ֮������ʱ�ݴ�ʷ��鮣���
�ڴ˽�é���ӣ������ж������Ͼ�������ʳ�˼��̻�������
Ů�·���Ϊ������ʳ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/fang" : 1,
      ]));
      set("exits", ([
          "northdown"  : __DIR__"guiyunge",
      ]));
      set("outdoors", "emei");
      setup();
      replace_program(ROOM);
}
