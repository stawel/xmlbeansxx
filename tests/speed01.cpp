#include <log4cxx/logger.h>
#include "c.h"
#include <fstream>
#include <sstream>
#include <xmlbeansxx/XmlParser.h>
#include <xmlbeansxx/TextUtils.h>

using namespace xmlbeansxx;
using namespace com::p4::mind::mytest;
using namespace std;

log4cxx::LoggerPtr LOG = log4cxx::Logger::getLogger("speed01");

double currentTime() {
    struct timeval tv;
    if (gettimeofday(&tv,NULL) != 0) throw IllegalStateException();
    return double(tv.tv_sec) + double(tv.tv_usec) / 1000000.0;
}

int main() {
    //Parsing speed test
    try {
        XmlParser parser(XmlParser::create());
        parser->loadGrammar("c.xsd");
        parser->getXmlOptions()->setValidation(false);
        ifstream inStream("d.xml");
        String in = TextUtils::istreamToString(inStream);
    
        while (true) {
            ContentDocument doc = ContentDocument::Factory::newInstance();
            double t1 = currentTime();
            parser->parse(in, doc);
            
            double t2 = currentTime();
            
            int car = 0;
            for (int i = 0; i < 10; i++) {
                car = (cast<Fullpersoninfo>(doc->getContent()->getEmployee()))->getCar();
                (cast<Fullpersoninfo>(doc->getContent()->getEmployee()))->setCar(car + 1);
            }

            {
                TreeType tree = (cast<Fullpersoninfo>(doc->getContent()->getEmployee()))->getTree()->getLeft()->getLeft();
                (cast<Fullpersoninfo>(doc->getContent()->getEmployee()))->getTree()->getRight()->getLeft()->setRight(tree);
            }
            
            double t3 = currentTime();
            
            string xml;
            xml = doc->toString();
            
            double t4 = currentTime();
            
            LOG4CXX_INFO(LOG, "Parse duration: " << (t2-t1) << " sec." << " " << 1. / (t2-t1) << " per second.");
            LOG4CXX_INFO(LOG, "Modify duration: " << (t3-t2) << " sec. " << (1. / (t3-t2)) << " per second.");
            LOG4CXX_INFO(LOG, "Serialize duration: " << (t4-t3) << " sec. " << (1. / (t4-t3)) << " per second.");
            LOG4CXX_INFO(LOG, "Car: " << car);
            //LOG4CXX_INFO(LOG, "Xml: " << xml);
        }
    } catch (xmlbeansxx::BeansException &e) {
        LOG4CXX_ERROR(LOG, "Exception: " + e.getMessage());
        throw e;
    }
    return 0;
}
